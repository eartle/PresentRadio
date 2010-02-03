
#include <QUrl>
#include <QDebug>
#include <QCryptographicHash>
#include <QNetworkReply>
#include <QTimer>

#include <qjson/parser.h>

#include <lastfm/Audioscrobbler>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "BluetoothDeviceInquiryMac.h"
#include "bluetoothdeviceinquiryinterface.h"
#include "CocoaInitializer.h"
#include "bluetoothdevicemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_settings("Coffey", "PresentRadio"),
    m_scrobbled(false)
{
    ui->setupUi(this);

    lastfm::ws::Username = m_settings.value("username", "username").toString();
    ui->username->setText(lastfm::ws::Username);
    m_password = m_settings.value("password", "password").toString();
    ui->rememberMe->setChecked(m_settings.value("remember", false).toBool());

    connect(&m_radio, SIGNAL(tick(qint64)), SLOT(onTick(qint64)));
    connect(&m_radio, SIGNAL(trackSpooled(lastfm::Track)), SLOT(onTrackSpooled(lastfm::Track)));

    connect(ui->playStop, SIGNAL(clicked(bool)), SLOT(onPlayStopClicked(bool)));
    connect(ui->skip, SIGNAL(clicked()), SLOT(onSkipClicked()));
    connect(ui->login, SIGNAL(clicked()), SLOT(onLoginClicked()));

    m_deviceModel = new BluetoothDeviceModel(this);
    ui->listView->setModel(m_deviceModel);

    connect(m_deviceModel, SIGNAL(found(int)), ui->btProgress, SLOT(setValue(int)));
    connect(m_deviceModel, SIGNAL(maximum(int)), ui->btProgress, SLOT(setMaximum(int)));

    m_cocoaInitializer = new CocoaInitializer();
    m_deviceInquiry = new BluetoothDeviceInquiry(m_deviceModel);
    m_deviceInquiry->start();
    ui->btProgress->setValue(0);

    connect(m_deviceModel, SIGNAL(devicesFound()), SLOT(onDevicesFound()));

    connect(ui->username, SIGNAL(textChanged(QString)), SLOT(onUsernameChanged(QString)));
    connect(ui->password, SIGNAL(textChanged(QString)), SLOT(onPasswordChanged(QString)));

    lastfm::ws::ApiKey = "52e420f41b41b041830694ecc3b383b6";
    lastfm::ws::SharedSecret = "11970cc8f4b06b833e9f74d1ebeb5553";

    if (ui->rememberMe->isChecked())
    {
        // login straight away
        ui->login->click();
    }
}

MainWindow::~MainWindow()
{
    m_settings.setValue("username", QString(lastfm::ws::Username));
    m_settings.setValue("password", m_password);
    m_settings.setValue("remember", ui->rememberMe->isChecked());

    delete ui;

    delete m_deviceInquiry;
    delete m_cocoaInitializer;
}

void MainWindow::onDevicesFound()
{
    // we have completed finding new bluetooth people present so return the radio

    QUrl blobbleUrl("http://jonty.co.uk/bits/blobble/scrobble.php");
    blobbleUrl.addQueryItem("user", lastfm::ws::Username);

    QString macs;

    for (int i(m_deviceModel->deviceCount() - 1) ; i >= 0 ; --i)
    {
        QString blobbleMac(m_deviceModel->deviceAt(i).macAddress);
        blobbleMac.replace(QChar('-'), QChar(':'));
        macs.append(blobbleMac + QString(i == 0 ? "" : ","));
    }

    blobbleUrl.addQueryItem("macs", macs);

    QNetworkRequest* blobbleRequest = new QNetworkRequest(blobbleUrl);
    m_blobbleReply = m_networkManager.get(*blobbleRequest);
    connect(m_blobbleReply, SIGNAL(finished()), SLOT(onBlobbleRequestFinished()));

    lastfm::RadioStation newStation = stationFromPresent();

    if (newStation.rql() != m_radio.station().rql())
    {
        m_radio.playNext(newStation);
    }

    // ask for a callback in 1 minute so we can discover devices again
    QTimer::singleShot(1 * 60 * 1000, this, SLOT(onTimerComplete()));
}

void MainWindow::onBlobbleRequestFinished()
{
    QByteArray data = m_blobbleReply->readAll();
}

void MainWindow::onTimerComplete()
{
    // find some devices again
    m_deviceInquiry->start();
    ui->btProgress->setMinimum(0);
    ui->btProgress->setMaximum(1);
    ui->btProgress->setValue(0);
}

void MainWindow::onTick(qint64 tick)
{
    ui->trackProgress->setValue(tick / 1000);

    if (!m_scrobbled)
    {
        if (( (tick / 1000) > (m_radio.currentTrack().duration() / 2)
            || (tick / 1000) > (4 * 60) )
            && (m_radio.currentTrack().duration() > 30) )
        {
            m_audioscrobbler->cache(m_radio.currentTrack());
            m_scrobbled = true;
        }
    }
}

void MainWindow::onUsernameChanged(const QString& username)
{
    lastfm::ws::Username = username;
}

void MainWindow::onPasswordChanged(const QString& password)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(password.toAscii());
    m_password = hash.result().toHex();
}

void MainWindow::onLoginClicked()
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(QString(lastfm::ws::Username + m_password).toAscii());
    QString authToken = hash.result().toHex();

    QUrl authUrl("http://ws.audioscrobbler.com/2.0/");
    authUrl.addQueryItem("api_key", lastfm::ws::ApiKey);
    authUrl.addQueryItem("authToken", authToken);
    authUrl.addQueryItem("method", "auth.getmobilesession");
    authUrl.addQueryItem("username", lastfm::ws::Username);

    QString apiSig = "api_key" + QString(lastfm::ws::ApiKey) + "authToken" + authToken + "method" + "auth.getmobilesession" + "username" + QString(lastfm::ws::Username) + lastfm::ws::SharedSecret;

    hash.reset();
    hash.addData(apiSig.toAscii());

    authUrl.addQueryItem("api_sig", hash.result().toHex());

    QNetworkRequest* request = new QNetworkRequest(authUrl);
    m_getMobileSessionReply = m_networkManager.get(*request);
    connect(m_getMobileSessionReply, SIGNAL(finished()), SLOT(onGetMobileSessionFinished()));

    ui->status->setText("Logging in...");
}

void MainWindow::onGetMobileSessionFinished()
{
    QDomDocument document;
    document.setContent(m_getMobileSessionReply->readAll());

    if (document.documentElement().attribute("status") == "ok")
    {
        lastfm::ws::SessionKey = document.documentElement().elementsByTagName("session").at(0).toElement().elementsByTagName("key").at(0).toElement().text().toAscii();
        ui->status->setText("Online");
        ui->playStop->setEnabled(true);

        m_audioscrobbler = new lastfm::Audioscrobbler("tst");
    }
    else
    {
        ui->status->setText("Failed!");
    }
}

void MainWindow::onTrackSpooled(const lastfm::Track& track)
{
    m_scrobbled = false;

    // submit any previous tracks
    m_audioscrobbler->submit();

    setWindowTitle(m_radio.station().rql());

    ui->trackProgress->setMinimum(0);
    ui->trackProgress->setMaximum(track.duration());

    ui->album->setText(track.album());
    ui->artist->setText(track.artist());
    ui->title->setText(track.title());

    m_trackGetInfoReply = track.getInfo();
    connect(m_trackGetInfoReply, SIGNAL(finished()), SLOT(onGetInfoFinished()));

    // send the now playing and cache the track so it can be submitted later
    m_audioscrobbler->nowPlaying(track);
}

void MainWindow::onGetInfoFinished()
{
    QDomDocument document;
    document.setContent(m_trackGetInfoReply->readAll());

    QUrl artworkUrl = document.documentElement().elementsByTagName("track").at(0).toElement().elementsByTagName("album").at(0).toElement().elementsByTagName("image").at(3).toElement().text();
    QNetworkRequest* artworkRequest = new QNetworkRequest(artworkUrl);
    m_artworkReply = m_networkManager.get(*artworkRequest);
    connect(m_artworkReply, SIGNAL(finished()), SLOT(onArtworkFinished()));
}

void MainWindow::onArtworkFinished()
{
    QPixmap artwork;
    artwork.loadFromData(m_artworkReply->readAll());
    ui->artwork->setPixmap(artwork.scaled(QSize(300, 300), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

lastfm::RadioStation MainWindow::stationFromPresent() const
{
    QString rql("user:" + QString(lastfm::ws::Username));

    for (int i(m_deviceModel->deviceCount() - 1) ; i >= 0 ; --i)
    {
        QString deviceName = m_deviceModel->deviceAt(i).name;

        if (!deviceName.isEmpty()
            && deviceName.startsWith("lfm-")
            && deviceName.mid(4) != QString(lastfm::ws::Username) )
        {
            rql += " or user:" + m_deviceModel->deviceAt(i).name.mid(4);
        }
    }

    return lastfm::RadioStation::rql(rql);
}

void MainWindow::onPlayStopClicked(bool checked)
{
    m_scrobbled = false;

    if (checked)
    {
        // start playing the radio for all the users that are present
        m_radio.play(stationFromPresent());

        ui->playStop->setText("Stop");
        ui->skip->setEnabled(true);
    }
    else
    {
        // stop playing stuff
        m_radio.stop();
        ui->playStop->setText("Play");
        ui->skip->setEnabled(false);
        ui->artwork->setPixmap(QPixmap());
        ui->album->setText("Album");
        ui->title->setText("Title");
        ui->artist->setText("Artist");
        ui->trackProgress->setValue(0);
    }
}

void MainWindow::onSkipClicked()
{
    m_radio.skip();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

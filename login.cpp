
#include <QTimer>
#include <QUrl>
#include <QCryptographicHash>
#include <QDesktopServices>
#include <QDomDocument>

#include <lastfm/ws.h>

#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // open the web page after a delay so the user gets time to read what is happening
    QTimer::singleShot(3000, this, SLOT(onTimerFinished()));
}

Login::~Login()
{
    delete ui;
}

void Login::onTimerFinished()
{
    // start authenticating
    QUrl getTokenUrl("http://ws.audioscrobbler.com/2.0/");
    getTokenUrl.addQueryItem("method", "auth.gettoken");
    getTokenUrl.addQueryItem("api_key", lastfm::ws::ApiKey);

    // sign the call
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString apiSig = "api_key" + QString(lastfm::ws::ApiKey) + "method" + "auth.gettoken" + lastfm::ws::SharedSecret;
    hash.reset();
    hash.addData(apiSig.toAscii());

    getTokenUrl.addQueryItem("api_sig", hash.result());

    QNetworkRequest* getTokenRequest = new QNetworkRequest(getTokenUrl);
    m_getTokenReply = m_networkManager.get(*getTokenRequest);
    connect(m_getTokenReply, SIGNAL(finished()), SLOT(onGetTokenFinished()));
}

void Login::onGetTokenFinished()
{
    QDomDocument document;
    document.setContent(m_getTokenReply->readAll());

    m_token = document.documentElement().elementsByTagName("token").at(0).toElement().text();

    QUrl authUrl("http://www.last.fm/api/auth/");
    authUrl.addQueryItem("api_key", lastfm::ws::ApiKey);
    authUrl.addQueryItem("token", m_token);

    QDesktopServices::openUrl(authUrl);
}

QString Login::token() const
{
    return m_token;
}

void Login::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

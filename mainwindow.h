#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Phonon>
#include <QNetworkAccessManager>
#include <QSettings>

#include "radio.h"

#include "bluetoothdeviceinquiryinterface.h"

class QNetworkReply;

namespace lastfm {class Audioscrobbler;}

class CocoaInitializer;
class BluetoothDeviceModel;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    lastfm::RadioStation stationFromPresent() const;

protected:
    void changeEvent(QEvent *e);

private slots:
    void onPlayStopClicked(bool checked);
    void onSkipClicked();
    void onDevicesFound();
    void onUsernameChanged(const QString& username);
    void onPasswordChanged(const QString& password);
    void onLoginClicked();
    void onGetMobileSessionFinished();
    void onTrackSpooled(const lastfm::Track& track);
    void onTimerComplete();
    void onTick(qint64 tick);
    void onGetInfoFinished();
    void onArtworkFinished();
    void onGetDataFinished();
    void onGetKeyFinished();
    void onGetModeFinished();
    void onGetTempoFinished();
    void onGetLoudnessFinished();
    void onBlobbleReply();

private:
    Ui::MainWindow *ui;

    bool m_scrobbled;

    QSettings m_settings;

    BluetoothDeviceModel* m_deviceModel;

    BluetoothDeviceInquiryInterface* m_deviceInquiry;
    CocoaInitializer* m_cocoaInitializer;

    Radio m_radio;
    lastfm::Audioscrobbler* m_audioscrobbler;

    QString m_password;

    QNetworkAccessManager m_networkManager;
    QNetworkReply* m_trackGetInfoReply;
    QNetworkReply* m_getMobileSessionReply;
    QNetworkReply* m_artworkReply;
    QNetworkReply* m_getDataReply;
    QNetworkReply* m_getKeyReply;
    QNetworkReply* m_getModeReply;
    QNetworkReply* m_getTempoReply;
    QNetworkReply* m_getLoudnessReply;
    QNetworkReply* m_blobbleReply;
};

#endif // MAINWINDOW_H

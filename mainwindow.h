#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Phonon>
#include <QNetworkAccessManager>
#include <QSettings>

#include "radio.h"

#include "bluetoothdeviceinquiryinterface.h"

class QNetworkReply;

class CocoaInitializer;
class BluetoothDeviceModel;
class ScrobSocket;
class Login;

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
    void onTrackSpooled(const lastfm::Track& track);
    void onTimerComplete();
    void onTick(qint64 tick);
    void onGetInfoFinished();
    void onArtworkFinished();
    void onBlobbleRequestFinished();
    void onLoginFinished(int result);
    void onGetSessionFinished();

private:
    Ui::MainWindow *ui;

    QSettings m_settings;

    BluetoothDeviceModel* m_deviceModel;

    BluetoothDeviceInquiryInterface* m_deviceInquiry;
    CocoaInitializer* m_cocoaInitializer;

    Radio m_radio;
    ScrobSocket* m_scrobSocket;

    Login* m_login;

    QNetworkAccessManager m_networkManager;
    QNetworkReply* m_trackGetInfoReply;
    QNetworkReply* m_artworkReply;
    QNetworkReply* m_blobbleReply;
    QNetworkReply* m_getSessionReply;
};

#endif // MAINWINDOW_H

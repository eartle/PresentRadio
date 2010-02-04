#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>

#include <QNetworkAccessManager>

namespace Ui {
    class Login;
}

class Login : public QDialog {
    Q_OBJECT
public:
    Login(QWidget *parent = 0);
    ~Login();

    QString token() const;

private slots:
    void onTimerFinished();
    void onGetTokenFinished();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Login *ui;

    QNetworkAccessManager m_networkManager;
    QNetworkReply* m_getTokenReply;

    QString m_token;
};

#endif // LOGIN_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jan 30 23:29:57 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *dataPron;
    QWidget *radioTab;
    QVBoxLayout *verticalLayout_4;
    QLabel *artwork;
    QLabel *title;
    QLabel *artist;
    QLabel *album;
    QProgressBar *trackProgress;
    QHBoxLayout *horizontalLayout;
    QPushButton *love;
    QPushButton *ban;
    QPushButton *playStop;
    QPushButton *skip;
    QWidget *btTab;
    QVBoxLayout *verticalLayout_3;
    QListView *listView;
    QProgressBar *btProgress;
    QWidget *settingsTab;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *username;
    QLineEdit *password;
    QCheckBox *rememberMe;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *login;
    QLabel *status;
    QSpacerItem *verticalSpacer;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *tempo;
    QLabel *tempoValue;
    QLabel *mode;
    QLabel *loudness;
    QLabel *key;
    QLabel *modeValue;
    QLabel *loudnessValue;
    QLabel *keyValue;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(350, 488);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dataPron = new QTabWidget(centralWidget);
        dataPron->setObjectName(QString::fromUtf8("dataPron"));
        radioTab = new QWidget();
        radioTab->setObjectName(QString::fromUtf8("radioTab"));
        verticalLayout_4 = new QVBoxLayout(radioTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        artwork = new QLabel(radioTab);
        artwork->setObjectName(QString::fromUtf8("artwork"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(artwork->sizePolicy().hasHeightForWidth());
        artwork->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(artwork);

        title = new QLabel(radioTab);
        title->setObjectName(QString::fromUtf8("title"));

        verticalLayout_4->addWidget(title);

        artist = new QLabel(radioTab);
        artist->setObjectName(QString::fromUtf8("artist"));

        verticalLayout_4->addWidget(artist);

        album = new QLabel(radioTab);
        album->setObjectName(QString::fromUtf8("album"));

        verticalLayout_4->addWidget(album);

        trackProgress = new QProgressBar(radioTab);
        trackProgress->setObjectName(QString::fromUtf8("trackProgress"));
        trackProgress->setValue(0);

        verticalLayout_4->addWidget(trackProgress);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        love = new QPushButton(radioTab);
        love->setObjectName(QString::fromUtf8("love"));
        love->setEnabled(false);

        horizontalLayout->addWidget(love);

        ban = new QPushButton(radioTab);
        ban->setObjectName(QString::fromUtf8("ban"));
        ban->setEnabled(false);

        horizontalLayout->addWidget(ban);

        playStop = new QPushButton(radioTab);
        playStop->setObjectName(QString::fromUtf8("playStop"));
        playStop->setEnabled(false);
        playStop->setCheckable(true);

        horizontalLayout->addWidget(playStop);

        skip = new QPushButton(radioTab);
        skip->setObjectName(QString::fromUtf8("skip"));
        skip->setEnabled(false);

        horizontalLayout->addWidget(skip);


        verticalLayout_4->addLayout(horizontalLayout);

        dataPron->addTab(radioTab, QString());
        btTab = new QWidget();
        btTab->setObjectName(QString::fromUtf8("btTab"));
        verticalLayout_3 = new QVBoxLayout(btTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        listView = new QListView(btTab);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setAlternatingRowColors(true);
        listView->setViewMode(QListView::ListMode);
        listView->setUniformItemSizes(false);

        verticalLayout_3->addWidget(listView);

        btProgress = new QProgressBar(btTab);
        btProgress->setObjectName(QString::fromUtf8("btProgress"));
        btProgress->setValue(0);

        verticalLayout_3->addWidget(btProgress);

        dataPron->addTab(btTab, QString());
        settingsTab = new QWidget();
        settingsTab->setObjectName(QString::fromUtf8("settingsTab"));
        verticalLayout_2 = new QVBoxLayout(settingsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        username = new QLineEdit(settingsTab);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout_2->addWidget(username);

        password = new QLineEdit(settingsTab);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(password);

        rememberMe = new QCheckBox(settingsTab);
        rememberMe->setObjectName(QString::fromUtf8("rememberMe"));

        verticalLayout_2->addWidget(rememberMe);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        login = new QPushButton(settingsTab);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout_2->addWidget(login);

        status = new QLabel(settingsTab);
        status->setObjectName(QString::fromUtf8("status"));

        horizontalLayout_2->addWidget(status);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        dataPron->addTab(settingsTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tempo = new QLabel(tab);
        tempo->setObjectName(QString::fromUtf8("tempo"));
        tempo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(tempo, 0, 0, 1, 1);

        tempoValue = new QLabel(tab);
        tempoValue->setObjectName(QString::fromUtf8("tempoValue"));

        gridLayout->addWidget(tempoValue, 0, 1, 1, 1);

        mode = new QLabel(tab);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mode, 1, 0, 1, 1);

        loudness = new QLabel(tab);
        loudness->setObjectName(QString::fromUtf8("loudness"));
        loudness->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(loudness, 2, 0, 1, 1);

        key = new QLabel(tab);
        key->setObjectName(QString::fromUtf8("key"));
        key->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(key, 3, 0, 1, 1);

        modeValue = new QLabel(tab);
        modeValue->setObjectName(QString::fromUtf8("modeValue"));

        gridLayout->addWidget(modeValue, 1, 1, 1, 1);

        loudnessValue = new QLabel(tab);
        loudnessValue->setObjectName(QString::fromUtf8("loudnessValue"));

        gridLayout->addWidget(loudnessValue, 2, 1, 1, 1);

        keyValue = new QLabel(tab);
        keyValue->setObjectName(QString::fromUtf8("keyValue"));

        gridLayout->addWidget(keyValue, 3, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        dataPron->addTab(tab, QString());

        verticalLayout->addWidget(dataPron);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        dataPron->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        artwork->setText(QString());
        title->setText(QApplication::translate("MainWindow", "Title", 0, QApplication::UnicodeUTF8));
        artist->setText(QApplication::translate("MainWindow", "Artist", 0, QApplication::UnicodeUTF8));
        album->setText(QApplication::translate("MainWindow", "Album", 0, QApplication::UnicodeUTF8));
        love->setText(QApplication::translate("MainWindow", "Love", 0, QApplication::UnicodeUTF8));
        ban->setText(QApplication::translate("MainWindow", "Ban", 0, QApplication::UnicodeUTF8));
        playStop->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        skip->setText(QApplication::translate("MainWindow", "Skip", 0, QApplication::UnicodeUTF8));
        dataPron->setTabText(dataPron->indexOf(radioTab), QApplication::translate("MainWindow", "Radio", 0, QApplication::UnicodeUTF8));
        dataPron->setTabText(dataPron->indexOf(btTab), QApplication::translate("MainWindow", "Bluetooth", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("MainWindow", "username", 0, QApplication::UnicodeUTF8));
        password->setText(QApplication::translate("MainWindow", "password", 0, QApplication::UnicodeUTF8));
        rememberMe->setText(QApplication::translate("MainWindow", "Remember me?", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        status->setText(QApplication::translate("MainWindow", "Offline", 0, QApplication::UnicodeUTF8));
        dataPron->setTabText(dataPron->indexOf(settingsTab), QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        tempo->setText(QApplication::translate("MainWindow", "Tempo:", 0, QApplication::UnicodeUTF8));
        tempoValue->setText(QString());
        mode->setText(QApplication::translate("MainWindow", "Mode:", 0, QApplication::UnicodeUTF8));
        loudness->setText(QApplication::translate("MainWindow", "Loudness:", 0, QApplication::UnicodeUTF8));
        key->setText(QApplication::translate("MainWindow", "Key:", 0, QApplication::UnicodeUTF8));
        modeValue->setText(QString());
        loudnessValue->setText(QString());
        keyValue->setText(QString());
        dataPron->setTabText(dataPron->indexOf(tab), QApplication::translate("MainWindow", "Data pr()n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName( "Present Radio" );
    a.setApplicationVersion( "0.1" );

    MainWindow w;
    w.show();
    return a.exec();
}

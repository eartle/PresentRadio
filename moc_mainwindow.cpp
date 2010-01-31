/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Jan 31 00:29:35 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      86,   77,   11,   11, 0x08,
     122,  113,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     201,  195,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     254,  249,   11,   11, 0x08,
     269,   11,   11,   11, 0x08,
     289,   11,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,
     329,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     368,   11,   11,   11, 0x08,
     389,   11,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0checked\0onPlayStopClicked(bool)\0"
    "onSkipClicked()\0onDevicesFound()\0"
    "username\0onUsernameChanged(QString)\0"
    "password\0onPasswordChanged(QString)\0"
    "onLoginClicked()\0onGetMobileSessionFinished()\0"
    "track\0onTrackSpooled(lastfm::Track)\0"
    "onTimerComplete()\0tick\0onTick(qint64)\0"
    "onGetInfoFinished()\0onArtworkFinished()\0"
    "onGetDataFinished()\0onGetKeyFinished()\0"
    "onGetModeFinished()\0onGetTempoFinished()\0"
    "onGetLoudnessFinished()\0onBlobbleReply()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onPlayStopClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: onSkipClicked(); break;
        case 2: onDevicesFound(); break;
        case 3: onUsernameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: onPasswordChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: onLoginClicked(); break;
        case 6: onGetMobileSessionFinished(); break;
        case 7: onTrackSpooled((*reinterpret_cast< const lastfm::Track(*)>(_a[1]))); break;
        case 8: onTimerComplete(); break;
        case 9: onTick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: onGetInfoFinished(); break;
        case 11: onArtworkFinished(); break;
        case 12: onGetDataFinished(); break;
        case 13: onGetKeyFinished(); break;
        case 14: onGetModeFinished(); break;
        case 15: onGetTempoFinished(); break;
        case 16: onGetLoudnessFinished(); break;
        case 17: onBlobbleReply(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

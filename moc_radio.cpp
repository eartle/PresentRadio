/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created: Sat Jan 30 14:53:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "radio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Radio[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       1,  119, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      38,    6,    6,    6, 0x05,
      66,    6,    6,    6, 0x05,
      81,    6,    6,    6, 0x05,
      97,   91,    6,    6, 0x05,
     117,    6,    6,    6, 0x25,
     128,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     149,  141,    6,    6, 0x0a,
     176,    6,    6,    6, 0x0a,
     183,    6,    6,    6, 0x0a,
     190,    6,    6,    6, 0x08,
     202,  200,    6,    6, 0x08,
     252,    6,    6,    6, 0x08,
     302,    6,    6,    6, 0x08,
     334,    6,    6,    6, 0x08,
     350,    6,    6,    6, 0x08,
     367,    6,    6,    6, 0x08,
     380,    6,    6,    6, 0x08,
     401,    6,    6,    6, 0x08,
     450,    6,    6,    6, 0x08,
     473,    6,    6,    6, 0x08,

 // enums: name, flags, count, data
     497, 0x0,    4,  123,

 // enum data: key, value
     503, uint(Radio::Stopped),
     511, uint(Radio::TuningIn),
     520, uint(Radio::Buffering),
     530, uint(Radio::Playing),

       0        // eod
};

static const char qt_meta_stringdata_Radio[] = {
    "Radio\0\0tuningIn(lastfm::RadioStation)\0"
    "trackSpooled(lastfm::Track)\0buffering(int)\0"
    "stopped()\0,data\0error(int,QVariant)\0"
    "error(int)\0tick(qint64)\0station\0"
    "play(lastfm::RadioStation)\0skip()\0"
    "stop()\0enqueue()\0,\0"
    "onPhononStateChanged(Phonon::State,Phonon::State)\0"
    "onPhononCurrentSourceChanged(Phonon::MediaSource)\0"
    "onTunerError(lastfm::ws::Error)\0"
    "phononEnqueue()\0onBuffering(int)\0"
    "onFinished()\0onMutedChanged(bool)\0"
    "onOutputDeviceChanged(Phonon::AudioOutputDevice)\0"
    "onVolumeChanged(qreal)\0setStationName(QString)\0"
    "State\0Stopped\0TuningIn\0Buffering\0"
    "Playing\0"
};

const QMetaObject Radio::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Radio,
      qt_meta_data_Radio, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Radio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Radio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Radio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Radio))
        return static_cast<void*>(const_cast< Radio*>(this));
    return QObject::qt_metacast(_clname);
}

int Radio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: tuningIn((*reinterpret_cast< const lastfm::RadioStation(*)>(_a[1]))); break;
        case 1: trackSpooled((*reinterpret_cast< const lastfm::Track(*)>(_a[1]))); break;
        case 2: buffering((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: stopped(); break;
        case 4: error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: play((*reinterpret_cast< const lastfm::RadioStation(*)>(_a[1]))); break;
        case 8: skip(); break;
        case 9: stop(); break;
        case 10: enqueue(); break;
        case 11: onPhononStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 12: onPhononCurrentSourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 13: onTunerError((*reinterpret_cast< lastfm::ws::Error(*)>(_a[1]))); break;
        case 14: phononEnqueue(); break;
        case 15: onBuffering((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: onFinished(); break;
        case 17: onMutedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: onOutputDeviceChanged((*reinterpret_cast< const Phonon::AudioOutputDevice(*)>(_a[1]))); break;
        case 19: onVolumeChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 20: setStationName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Radio::tuningIn(const lastfm::RadioStation & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Radio::trackSpooled(const lastfm::Track & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Radio::buffering(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Radio::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Radio::error(int _t1, const QVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void Radio::tick(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

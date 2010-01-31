/****************************************************************************
** Meta object code from reading C++ file 'bluetoothdevicemodel.h'
**
** Created: Sun Jan 31 00:22:25 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetoothdevicemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothdevicemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothDeviceModel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      46,   37,   21,   21, 0x05,
      65,   57,   21,   21, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothDeviceModel[] = {
    "BluetoothDeviceModel\0\0devicesFound()\0"
    "numFound\0found(int)\0maximum\0maximum(int)\0"
};

const QMetaObject BluetoothDeviceModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_BluetoothDeviceModel,
      qt_meta_data_BluetoothDeviceModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothDeviceModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothDeviceModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothDeviceModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothDeviceModel))
        return static_cast<void*>(const_cast< BluetoothDeviceModel*>(this));
    if (!strcmp(_clname, "BluetoothDeviceInquiryObserver"))
        return static_cast< BluetoothDeviceInquiryObserver*>(const_cast< BluetoothDeviceModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int BluetoothDeviceModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: devicesFound(); break;
        case 1: found((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: maximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void BluetoothDeviceModel::devicesFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void BluetoothDeviceModel::found(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothDeviceModel::maximum(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

#ifndef BLUETOOTHDEVICEINQUIRYINTERFACE_H
#define BLUETOOTHDEVICEINQUIRYINTERFACE_H

#include <QString>

class BluetoothDeviceInquiryObserver
{
public:
    virtual void nameUpdated(const QString& name, const QString& macAddress, int numLeft) = 0;
};

class BluetoothDeviceInquiryInterface
{
public:
    virtual ~BluetoothDeviceInquiryInterface(){;}
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif // BLUETOOTHDEVICEINQUIRYINTERFACE_H

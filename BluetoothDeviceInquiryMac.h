
#include "bluetoothdeviceinquiryinterface.h"

class BluetoothDeviceInquiry : public BluetoothDeviceInquiryInterface
{
public:
    BluetoothDeviceInquiry(BluetoothDeviceInquiryObserver* observer);
    ~BluetoothDeviceInquiry();

    void start();
    void stop();

private:
    class Private;
    Private* impl;
};



#include <QDebug>

#include <IOBluetooth/objc/IOBluetoothDeviceInquiry.h>
#include <IOBluetooth/objc/IOBluetoothDevice.h>
#include <Foundation/NSObject.h>

#include "BluetoothDeviceInquiryMac.h"

#include <Carbon/Carbon.h>
#include <Cocoa/Cocoa.h>
#include <QString>

void setBufferFromCFString(QString& qs, CFStringRef cfs)
{
    if (!cfs)
        return;

    CFIndex size = CFStringGetLength(cfs);
    UniChar fixedSizeBuffer[1024];
    UniChar *buffer;

    if (size > (CFIndex)(sizeof(fixedSizeBuffer) / sizeof(UniChar))) {
        buffer = (UniChar *)malloc(size * sizeof(UniChar));
    } else {
        buffer = fixedSizeBuffer;
    }

    CFStringGetCharacters(cfs, CFRangeMake (0, size), buffer);

    qs.setUnicode((const QChar *)buffer, (uint)size);

    if (buffer != fixedSizeBuffer)
        free(buffer);
}

QString qStringfromCFString(CFStringRef cfs)
{
    QString qs;
    setBufferFromCFString(qs, cfs);
    return qs;
}

QString qStringfromNSString(NSString *nss)
{
    QString qs;
    setBufferFromCFString(qs, (CFStringRef)nss);
    return qs;
}

@interface Delegate : NSObject {
    BluetoothDeviceInquiryObserver* m_observer;
}
        - (Delegate*) init:(BluetoothDeviceInquiryObserver*)observer;
    - (void) deviceInquiryDeviceNameUpdated:(IOBluetoothDeviceInquiry*)sender
        device:(IOBluetoothDevice*)device devicesRemaining:(uint32_t)devicesRemaining;
@end


@implementation Delegate
- (id) init:(BluetoothDeviceInquiryObserver*)observer
{
    if ( self = [super init] )
    {
        self->m_observer = observer;
    }

    return self;
}


- (void) deviceInquiryDeviceNameUpdated:(IOBluetoothDeviceInquiry*)sender
        device:(IOBluetoothDevice*)device devicesRemaining:(uint32_t)devicesRemaining
{
    NSString* nsName = [device getName];
    NSString* nsAddressString = [device getAddressString];

    QString name = qStringfromNSString(nsName);
    QString addressString = qStringfromNSString(nsAddressString);

    m_observer->nameUpdated(name, addressString, devicesRemaining);
}
@end

class BluetoothDeviceInquiry::Private
{
public:
    IOBluetoothDeviceInquiry* deviceInquiry;
    Delegate* delegate;
};

BluetoothDeviceInquiry::BluetoothDeviceInquiry(BluetoothDeviceInquiryObserver* observer)
{
    impl = new Private;

    impl->delegate = [[Delegate alloc] init: observer];

    impl->deviceInquiry = [IOBluetoothDeviceInquiry inquiryWithDelegate: impl->delegate];
}

BluetoothDeviceInquiry::~BluetoothDeviceInquiry()
{
    [impl->deviceInquiry release];
    delete impl;
}

void BluetoothDeviceInquiry::start()
{
    [impl->deviceInquiry start];
}

void BluetoothDeviceInquiry::stop()
{
    [impl->deviceInquiry stop];
}


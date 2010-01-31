#ifndef BLUETOOTHDEVICEMODEL_H
#define BLUETOOTHDEVICEMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QString>

#include "bluetoothdeviceinquiryinterface.h"

struct BluetoothDevice
{
    QString name;
    QString macAddress;
};

class BluetoothDeviceModel : public QAbstractItemModel, public BluetoothDeviceInquiryObserver
{
Q_OBJECT
public:
    explicit BluetoothDeviceModel(QObject *parent = 0);

    int deviceCount() const;
    BluetoothDevice deviceAt(int index) const;

private:
    void nameUpdated(const QString& name, const QString& macAddress, int numLeft);

private:
    QModelIndex index(int row, int column, const QModelIndex & parent) const;
    QModelIndex parent ( const QModelIndex & index ) const;
    int rowCount ( const QModelIndex & parent ) const;
    int columnCount ( const QModelIndex & parent ) const;
    QVariant data ( const QModelIndex & index, int role ) const;

signals:
    void devicesFound();
    void found(int numFound);
    void maximum(int maximum);

public slots:

private:
    QList<BluetoothDevice> m_devices;

    int m_totalDevices;
    int m_lastNumLeft;
};

#endif // BLUETOOTHDEVICEMODEL_H

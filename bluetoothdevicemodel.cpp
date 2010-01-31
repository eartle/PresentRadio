#include "bluetoothdevicemodel.h"

BluetoothDeviceModel::BluetoothDeviceModel(QObject *parent) :
    QAbstractItemModel(parent), m_lastNumLeft(0)
{
}

void BluetoothDeviceModel::nameUpdated(const QString& name, const QString& macAddress, int numLeft)
{
    BluetoothDevice device;
    device.name = name;
    device.macAddress = macAddress;

    if (numLeft > m_lastNumLeft)
        {
        // we have started to find devices again
        m_totalDevices = numLeft + 1;
        emit maximum(m_totalDevices);
        m_devices.clear();
        }

    m_devices.append(device);
    emit layoutChanged();

    m_lastNumLeft = numLeft;

    emit found(m_totalDevices - numLeft);

    if (numLeft == 0)
        emit devicesFound();
}

int BluetoothDeviceModel::deviceCount() const
{
    return m_devices.count();
}

BluetoothDevice BluetoothDeviceModel::deviceAt(int index) const
{
    return m_devices[index];
}

QModelIndex BluetoothDeviceModel::index(int row, int column, const QModelIndex & parent) const
{
    return createIndex(row, column);
}

QModelIndex BluetoothDeviceModel::parent ( const QModelIndex & index ) const
{
    return QModelIndex();
}

int BluetoothDeviceModel::rowCount ( const QModelIndex & parent ) const
{
    return m_devices.count();
}

int BluetoothDeviceModel::columnCount ( const QModelIndex & parent ) const
{
    return 1;
}

QVariant BluetoothDeviceModel::data ( const QModelIndex & index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_devices[index.row()].name + " " + m_devices[index.row()].macAddress;
    }

    return QVariant();
}

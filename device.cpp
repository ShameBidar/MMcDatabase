#include "device.h"

QString Device::getIpaddr() const
{
    return ipaddr;
}

void Device::setIpaddr(const QString &value)
{
    ipaddr = value;
}

QString Device::getNetmask() const
{
    return netmask;
}

void Device::setNetmask(const QString &value)
{
    netmask = value;
}

QString Device::getGateway() const
{
    return gateway;
}

void Device::setGateway(const QString &value)
{
    gateway = value;
}

QString Device::getEthaddr() const
{
    return ethaddr;
}

void Device::setEthaddr(const QString &value)
{
    ethaddr = value;
}

QString Device::getPlace() const
{
    return place;
}

void Device::setPlace(const QString &value)
{
    place = value;
}

QString Device::getWagonNumber() const
{
    return wagonNumber;
}

void Device::setWagonNumber(const QString &value)
{
    wagonNumber = value;
}

QString Device::getName() const
{
    return name;
}

void Device::setName(const QString &value)
{
    name = value;
}

QString Device::getStreamAddress() const
{
    return streamAddress;
}

void Device::setStreamAddress(const QString &value)
{
    streamAddress = value;
}

QString Device::getChNumber() const
{
    return chNumber;
}

void Device::setChNumber(const QString &value)
{
    chNumber = value;
}

int Device::getCamPosition() const
{
    return camPosition;
}

void Device::setCamPosition(int value)
{
    camPosition = value;
}

Device_Type Device::getType() const
{
    return type;
}

void Device::setType(const Device_Type &value)
{
    type = value;
}

int Device::getNumberOfDevices() const
{
    return numberOfDevices;
}

Device::Device(QString ipaddr,QString netmask,QString gateway,QString ethaddr,QObject *parent) : QObject(parent)
{
    this->ipaddr=ipaddr;
    this->netmask=netmask;
    this->gateway=gateway;
    this->ethaddr=ethaddr;
}



bool Device::operator==(const Device& device)
{
    return(this->ipaddr==(device.ipaddr));
}

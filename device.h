#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <devicetype.h>

class Device : public QObject
{
    Q_OBJECT
protected:
    QString ipaddr;
    QString netmask;
    QString gateway;
    QString ethaddr;
    QString place;
    QString wagonNumber;
    Device_Type type;
    QString name;
    QString streamAddress;
    QString chNumber;
    int camPosition;
    int numberOfDevices;
public:
    bool isOnline;
    int offlinecnt;
    explicit Device(QString ipaddr,QString netmask,QString gateway,QString ethaddr,QObject *parent = nullptr);

   // virtual void add(QString ip);
   // virtual void remove(QString ip);

    bool operator==(const Device &device);

    QString getIpaddr() const;
    void setIpaddr(const QString &value);

    QString getNetmask() const;
    void setNetmask(const QString &value);

    QString getGateway() const;
    void setGateway(const QString &value);

    QString getEthaddr() const;
    void setEthaddr(const QString &value);

    QString getPlace() const;
    void setPlace(const QString &value);

    QString getWagonNumber() const;
    void setWagonNumber(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getStreamAddress() const;
    void setStreamAddress(const QString &value);

    QString getChNumber() const;
    void setChNumber(const QString &value);

    int getCamPosition() const;
    void setCamPosition(int value);

    Device_Type getType() const;
    void setType(const Device_Type &value);

    int getNumberOfDevices() const;

signals:

public slots:
};

#endif // DEVICE_H

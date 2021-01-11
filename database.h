#ifndef DATABASE_H
#define DATABASE_H

#include "device.h"
#include <QDir>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

class DataBase : public QObject
{
    Q_OBJECT
public:
    typedef struct
    {
        QString ip;
        QString netmask;
        QString password;
        int auto_disksize;
        int man_disksize;
        int emg_disksize;
        bool is_autotime;
    }SettingInfo_t;

    enum DEVICE_FIELD
    {
        DEVICE_NAME,
        DEVICE_TYPE,
        DEVICE_IP,
        DEVICE_MAC,
        DEVICE_GATEWAY,
        DEVICE_NETMASK,
        DEVICE_PLACE,
        DEVICE_STREAM,
        DEVICE_WAGON_NOM,
        DEVICE_CHANNEL_NOM,
        DEVICE_CAMERA_POS,
    };
    enum SETTING_FIELD
    {
        SETTING_IP,
        SETTING_NETMASK,
        SETTING_PASSWORD,
        SETTING_AUTOMAN_TIME,
        SETTING_AUTODISK_SIZE,
        SETTING_MANDISK_SIZE,
        SETTING_EMGDISK_SIZE,
    };

    DataBase(QObject* parent = 0);
    void updateSettingFields(SETTING_FIELD in_field, QString in_val);
    void updateSettingFields(SETTING_FIELD in_field, int in_val);
    void updateSettingFields(SETTING_FIELD in_field, bool in_val);
    void insertDevRecord(Device* in_dev);
    void removeDevRecord(Device* in_dev);


private:
    QString db_name;
    SettingInfo_t setting_info;

};

#endif // DATABASE_H

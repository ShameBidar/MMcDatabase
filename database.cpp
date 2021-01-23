#include "database.h"
#include "macros.h"
#include <QDebug>

DataBase::DataBase(QObject* parent) : QObject(parent)
{

    db_name = DATABASE_NAME;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(QDRIVER);
        db.setDatabaseName(db_name);
        if(db.open())
        {
            QSqlQuery qc;
            QString cmd;

            /////////////////////// create  device table ///////////////////////
            cmd = "CREATE TABLE  IF NOT EXISTS device (id INTEGER PRIMARY KEY AUTOINCREMENT, Name VARCHAR(30), Type INTEGER, IP VARCHAR(30), Mac VARCHAR(60), Gateway VARCHAR(30), Netmask VARCHAR(30), Place VARCHAR(30), Stream VARCHAR(30), WagonNom VARCHAR(30), CHNom VARCHAR(30), CameraPos INTEGER)";
            if(!qc.exec(cmd))
            {
                qWarning() << "MainWindow::DatabaseInit - ERROR: " << qc.lastError().text();
            }
            else
            {

            }

            /////////////////////// create setting table ///////////////////////
            cmd = "CREATE TABLE  IF NOT EXISTS setting (IP VARCHAR(30), Netmask VARCHAR(30), AutoTimeSetting BOOL, AutoDiskSize INTEGER,  ManDiskSize INTEGER, EmgDiskSize INTEGER, Password VARCHAR(30))";
            if(!qc.exec(cmd))
            {
                qWarning() << "MainWindow::DatabaseInit - ERROR: " << qc.lastError().text();
            }
            else
            {
                QSqlQuery qs("SELECT COUNT(*) FROM setting");
                if(qs.next())
                {
                    int row_count = qs.value(0).toInt();
                    if(row_count == 0)
                    {
                        QSqlQuery qi;
                        cmd = "INSERT INTO setting (IP, Netmask , AutoTimeSetting, AutoDiskSize,  ManDiskSize, EmgDiskSize, Password) VALUES (' ',' ',TRUE,0,0,0,' ')";
                        if(!qi.exec(cmd))
                            qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qi.lastError().text();
                    }
                    else
                    {

                    }
                }

            }
        }
        else
        {
            qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << QDRIVER << " available";
        }

    }
    QSqlDatabase::removeDatabase(db_name);

}


void DataBase::insertDevRecord(Device* in_dev)
{

    QString name = in_dev->getName();
    int type = (int) in_dev->getType();
    QString mac = in_dev->getEthaddr();
    QString gateway = in_dev->getGateway();
    QString ip_addr = in_dev->getIpaddr();
    QString net_mask = in_dev->getNetmask();
    QString place = in_dev->getPlace();
    QString stream = in_dev->getStreamAddress();
    QString wagon_nom = in_dev->getWagonNumber();
    QString chnom = in_dev->getChNumber();
    int camera_pos = in_dev->getCamPosition();

    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qi;
         QString cmd = QString("INSERT INTO device (Name,Type,IP,Mac,Gateway,Netmask,Place,Stream,WagonNom,CHNom,CameraPos) VALUES ('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11')").
                 arg(name).arg(type).arg(ip_addr).arg(mac).arg(gateway).arg(net_mask).arg(place).arg(stream).arg(wagon_nom).arg(chnom).arg(camera_pos);
         if(!qi.exec(cmd))
             qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qi.lastError().text();
     }
     QSqlDatabase::removeDatabase(db_name);

}

void DataBase::removeDevRecord(Device* in_dev)
{

    QString name = in_dev->getName();
    int type = (int) in_dev->getType();
    QString mac = in_dev->getEthaddr();
    QString gateway = in_dev->getGateway();
    QString ip_addr = in_dev->getIpaddr();
    QString net_mask = in_dev->getNetmask();
    QString place = in_dev->getPlace();
    QString stream = in_dev->getStreamAddress();
    QString wagon_nom = in_dev->getWagonNumber();
    QString chnom = in_dev->getChNumber();
    int camera_pos = in_dev->getCamPosition();

    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qi;
         QString cmd = QString("DELETE FROM device WHERE Name='%1' AND Type='%2' AND IP='%3' AND Mac='%4' AND Gateway='%5' AND Netmask='%6' AND Place='%7' AND Stream='%8' AND WagonNom='%9' AND CHNom='%10' AND CameraPos='%11'").
                 arg(name).arg(type).arg(ip_addr).arg(mac).arg(gateway).arg(net_mask).arg(place).arg(stream).arg(wagon_nom).arg(chnom).arg(camera_pos);
         if(!qi.exec(cmd))
             qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qi.lastError().text();
     }
     QSqlDatabase::removeDatabase(db_name);

}


void DataBase::updateSettingFields(DataBase::SETTING_FIELD in_field, QString in_val)
{
    QString cmd;
    if(in_field == DataBase::SETTING_IP)
    {
        cmd = QString("UPDATE setting Set IP = '%1'").arg(in_val);
    }
    else if(in_field == DataBase::SETTING_NETMASK)
    {
        cmd = QString("UPDATE setting Set Netmask = '%1'").arg(in_val);
    }
    else if(in_field == DataBase::SETTING_PASSWORD)
    {
        cmd = QString("UPDATE setting Set Password = '%1'").arg(in_val);
    }

    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qu;
         if(!qu.exec(cmd))
             qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qu.lastError().text();
     }
     QSqlDatabase::removeDatabase(db_name);

}

void DataBase::updateSettingFields(DataBase::SETTING_FIELD in_field, int in_val)
{
    QString cmd;
    if(in_field == DataBase::SETTING_EMGDISK_SIZE)
    {
        cmd = QString("UPDATE setting Set EmgDiskSize = '%1'").arg(in_val);
    }
    else if(in_field == DataBase::SETTING_AUTODISK_SIZE)
    {
        cmd = QString("UPDATE setting Set AutoDiskSize = '%1'").arg(in_val);
    }
    else if(in_field == DataBase::SETTING_MANDISK_SIZE)
    {
        cmd = QString("UPDATE setting Set ManDiskSize = '%1'").arg(in_val);
    }

    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qu;
         if(!qu.exec(cmd))
             qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qu.lastError().text();
     }
     QSqlDatabase::removeDatabase(db_name);

}

void DataBase::updateSettingFields(DataBase::SETTING_FIELD in_field, bool in_val)
{
    QString cmd;
    if(in_field == DataBase::SETTING_AUTOMAN_TIME)
    {
        cmd = QString("UPDATE setting Set AutoTimeSetting = '%1'").arg(in_val);
    }

    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qu;
         if(!qu.exec(cmd))
             qWarning() << "MainWindow::DatabasePopulate - ERROR: " << qu.lastError().text();
     }
     QSqlDatabase::removeDatabase(db_name);

}


void DataBase::getSettingRecods(DataBase::SettingInfo_t& out_record)
{
    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qs("SELECT IP, Netmask, AutoTimeSetting, AutoDiskSize,  ManDiskSize, EmgDiskSize, Password FROM setting");
         if(qs.next())
         {
             out_record.ip = qs.value(0).toString();
             out_record.netmask = qs.value(1).toString();
             out_record.is_autotime = qs.value(2).toBool();
             out_record.auto_disksize = qs.value(3).toInt();
             out_record.man_disksize = qs.value(4).toInt();
             out_record.emg_disksize = qs.value(5).toInt();
             out_record.password = qs.value(6).toString();

         }
     }
     QSqlDatabase::removeDatabase(db_name);
}


void DataBase::getDevRecords(QList<DataBase::DevInfo_t>& out_record)
{
    {
         QSqlDatabase db = QSqlDatabase::database(db_name);
         QSqlQuery qs("SELECT Name,Type,IP,Mac,Gateway,Netmask,Place,Stream,WagonNom,CHNom,CameraPos FROM device");
         while(qs.next())
         {
             DevInfo_t device;
             device.name = qs.value(0).toString();
             device.type = qs.value(1).toInt();
             device.ip = qs.value(2).toString();
             device.mac = qs.value(3).toString();
             device.gateway = qs.value(4).toString();
             device.netmask = qs.value(5).toString();
             device.place = qs.value(6).toString();
             device.stream = qs.value(7).toString();
             device.wagon_nom = qs.value(8).toString();
             device.channel_nom = qs.value(9).toString();
             device.camera_position = qs.value(10).toInt();
             out_record.append(device);
         }
     }
     QSqlDatabase::removeDatabase(db_name);
}

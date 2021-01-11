#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "device.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_database = new DataBase(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_insert_released()
{
    QString str = ui->ledit_string->text();
    QString str_int = ui->ledit_integer->text();
    int nom = str_int.toInt();
    Device* dev = new Device(str,str,str,str,this);
    dev->setName(str);
    dev->setType(PIS);
    dev->setChNumber(str);
    dev->setCamPosition(nom);
    dev->setWagonNumber(str);
    dev->setPlace(str);
    dev->setStreamAddress(str);
    p_database->insertDevRecord(dev);
}



void MainWindow::on_btn_delete_released()
{
    QString str = ui->ledit_string->text();
    QString str_int = ui->ledit_integer->text();
    int nom = str_int.toInt();
    Device* dev = new Device(str,str,str,str,this);
    dev->setName(str);
    dev->setType(PIS);
    dev->setChNumber(str);
    dev->setCamPosition(nom);
    dev->setWagonNumber(str);
    dev->setPlace(str);
    dev->setStreamAddress(str);
    p_database->removeDevRecord(dev);
}

void MainWindow::on_btn_update_released()
{
    QString str = ui->ledit_string->text();
    QString str_int = ui->ledit_integer->text();
    int nom = str_int.toInt();
    p_database->updateSettingFields(DataBase::SETTING_PASSWORD,str);
    p_database->updateSettingFields(DataBase::SETTING_AUTODISK_SIZE,nom);

}

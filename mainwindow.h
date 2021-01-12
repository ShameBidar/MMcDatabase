#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_insert_released();
    void on_btn_delete_released();

    void on_btn_update_released();

    void on_btn_showdev_released();

private:
    Ui::MainWindow *ui;
    DataBase* p_database;

};
#endif // MAINWINDOW_H

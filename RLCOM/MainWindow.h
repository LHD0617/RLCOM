/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: MainWindow.h
 * Description: 主窗口头文件
 * Change Logs:
  |Date          |Author       |Notes     			|version
  |2022-09-17    |满心欢喜     |Initial build     	|1.0.0
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*  @include  */
#include <QDebug>
#include <QTimer>
#include <QSerialPortInfo>
#include <QMainWindow>
#include <QSerialPort>

/* @define MAX_BAUDLIST */
#define MAX_BAUDLIST 17

/* 波特率列表 */
const QString BaudList[MAX_BAUDLIST] =
{
    "9600",
    "19200",
    "38400",
    "57600",
    "115200",
    "460800",
    "500000",
    "576000",
    "921600",
    "1000000",
    "1152000",
    "1500000",
    "2000000",
    "2500000",
    "3000000",
    "3500000",
    "4000000",
};

/* 数据位列表 */
const QString DataBitList[4] =
{
    "5",
    "6",
    "7",
    "8",
};

/* 校验位列表 */
const QString CheckBitList[3] =
{
    "无校验",
    "偶校验",
    "奇校验",
};

/* 停止位列表 */
const QString StopBitList[3] =
{
    "1",
    "2",
    "1.5",
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool SwitchPortFlag = false;
    QSerialPort Ser;
    QStringList PortList;
    QTimer RefreshPortTimer;

public slots:
    void RefreshPort();
    void SwitchPort();
    void ShowMessage(QString Message);
};
#endif // MAINWINDOW_H

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
#include <QKeyEvent>
#include <QtWidgets/QLabel>
#include <QSerialPortInfo>
#include <QMainWindow>
#include <QSerialPort>

/* @define MAX_BAUDLIST */
#define ConfigureFileName "ConfigureFile.ini"

/* @define MAX_BAUDLIST */
#define MAX_BAUDLIST 17

/* 波特率列表 */
const QString BaudList[MAX_BAUDLIST] =
{
    "9600", "19200", "38400", "57600", "115200", "460800", "500000", "576000", "921600",
    "1000000", "1152000", "1500000", "2000000", "2500000", "3000000", "3500000", "4000000",
};

/* 数据位列表 */
const QString DataBitList[4] =
{
    "5", "6", "7", "8",
};

/* 校验位列表 */
const QString CheckBitList[3] =
{
    "无校验", "偶校验", "奇校验",
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

    bool SwitchPortFlag = false;        /* 端口开启状态 */

    uint32_t ReceiveCount = 0;          /* 接收数据量 */

    uint32_t ReceiveLastCount = 0;      /* 上一次接收数据量 */

    uint32_t ReceiveSpeed = 0;          /* 接收速度 */

    uint32_t SendCount = 0;             /* 发送数据量 */

    QSerialPort Ser;                    /* 串口对象*/

    QString NowTime;                    /* 当前时间 */

    QStringList PortList;               /* 端口列表 */

    QLabel* TimeLab;                    /* 当前时间Label */

    QLabel* DataLab;                    /* 数据信息Label */

    QTimer AutoSendTimer;               /* 定时发送定时器 */

    QTimer RefreshPortTimer;            /* 刷新串口定时器 10Hz */

    QTimer UpdateTimeTimer;             /* 更新时间定时器 1Hz */

public slots:
    void RefreshPort();

    void SwitchPort();

    void CleanReceiveData();

    void CleanStats();

    void CleanSendData();

    void ReceiveData();

    void SendData();

    void AutoSend(int state);

    void WriteConfigure();

    void ReadConfigure();

    bool eventFilter(QObject *obj, QEvent *event);

    void UpdateTime();

    void ShowMessage(QString Message);
};

QString ByteArrayToHexString(QByteArray ascii);

QByteArray StringToQByteArray(QString str);

QByteArray HexStringToQByteArray(QString str);

char ConvertCharToHex(char ch);

QString ReadLineChars(FILE* fp, uint32_t line);

#endif // MAINWINDOW_H
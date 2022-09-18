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
#include "qcustomplot.h"

/* @define MAX_BAUDLIST */
#define ConfigureFileName "ConfigureFile.ini"

/* @define MAX_BAUDLIST */
#define MAX_BAUDLIST 17

/* @define PIXEL_SIZE */
#define PIXEL_SIZE 5

/* @define MAX_X_AXIS */
#define MAX_X_AXIS 1000

/* @define MIN_X_AXIS */
#define MIN_X_AXIS 50

/* 图传帧头 */
const uint8_t ImageHeadData[4] =
{
    0x00, 0xff, 0x01, 0x01
};

/* 示波帧头 */
const uint8_t ChartHeadData[4] =
{
    0x00, 0xff, 0x02, 0x02
};

/* 示波帧头 */
const QColor ChartGraphColor[8] =
{
    0xff0000, 0x00ff00, 0x8080ff, 0xffff00,
    0xff00ff, 0x00ffff, 0xffb2f8, 0xaaff00,
};

/* @class UnitChartLabel */
class UnitChartLabel : public QWidget
{

    Q_OBJECT

public:
    QGridLayout* Layout;

    QCheckBox* CheckBox;

    QLineEdit* LineEdit;

    QLabel* Label;

    UnitChartLabel(QColor color)
    {
        Layout = new QGridLayout();

        CheckBox = new QCheckBox();

        LineEdit = new QLineEdit();

        Label = new QLabel("0");

        CheckBox->setChecked(true);

        LineEdit->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        Layout->addWidget(CheckBox, 0, 0, 1, 1);

        Layout->addWidget(LineEdit, 0, 1, 1, 1);

        Label->setFrameShape(QFrame::Box);

        Label->setStyleSheet(QString("QLabel{color:black; background-color:rgb(%1,%2,%3);}")
                             .arg(color.red()).arg(color.green()).arg(color.blue()));

        Label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        Layout->addWidget(Label, 1, 0, 1, 2);

        this->setLayout(Layout);
    }
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

    bool SwitchImageFlag = false;       /* 图传开启状态 */

    bool SwitchChartFlag = false;       /* 波形开启状态 */

    bool ImageHeadFlag = false;         /* 图传帧头标志位 */

    bool ChartHeadFlag = false;         /* 波形帧头标志位 */

    bool ShowImageFlag = false;         /* 显示图像状态标志位 */

    uint8_t ImageHeadLen = 0;           /* 图传帧头长度 */

    uint8_t ChartHeadLen = 0;           /* 示波帧头长度 */

    uint8_t Channle = 0;                /* 波形通道数 */

    uint8_t DataType = 0;               /* 波形数据类型 */

    uint16_t Height;                    /* 图像高度 */

    uint16_t Width;                     /* 图像宽度 */

    uint32_t ImageDataSize;             /* 图像数据大小 */

    uint32_t ChartDataSize;             /* 示波数据大小 */

    uint32_t ReceiveCount = 0;          /* 接收数据量 */

    uint32_t ReceiveLastCount = 0;      /* 上一次接收数据量 */

    uint32_t ReceiveSpeed = 0;          /* 接收速度 */

    uint32_t SendCount = 0;             /* 发送数据量 */

    uint32_t ChartCount = 0;            /* 示波数据量 */

    uint32_t ChartXRange = 300;         /* 示波X轴缩放*/

    QByteArray UartData;                /* 图像数据 */

    QByteArray ImageData;               /* 图像数据 */

    UnitChartLabel* ChartLabel[8];      /* 示波标签 */

    QSerialPort Ser;                    /* 串口对象*/

    QString NowTime;                    /* 当前时间 */

    QStringList PortList;               /* 端口列表 */

    QLabel* TimeLab;                    /* 当前时间Label */

    QLabel* DataLab;                    /* 数据信息Label */

    QLabel* MousePostLab;               /* 鼠标位置Label */

    QTimer AutoSendTimer;               /* 定时发送定时器 */

    QTimer RefreshPortTimer;            /* 刷新串口定时器 10Hz */

    QTimer UpdateTimeTimer;             /* 更新时间定时器 1Hz */

public slots:
    void RefreshPort();

    void SwitchPort();

    void CleanReceiveData();

    void CleanStats();

    void CleanSendData();

    void SwitchImage();

    void SwitchChart();

    void ReceiveData();

    void SendData();

    void AutoSend(int state);

    void WriteConfigure();

    void ReadConfigure();

    QImage MakeImage();

    void XAxisShrink();

    void XAxisZoom();

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

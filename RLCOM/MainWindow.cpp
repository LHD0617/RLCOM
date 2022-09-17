/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: MainWindow.h
 * Description: 主窗口头文件
 * Change Logs:
  |Date          |Author       |Notes     			|version
  |2022-09-17    |满心欢喜     |Initial build     	|1.0.0
 */

/*  @include  */
#include "MainWindow.h"
#include "ui_MainWindow.h"


/**
    * @name		MainWindow
    * @brief  	构造函数
  */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TimeLab = new QLabel();

    DataLab = new QLabel(QString("共接收%1字节，速度%2字节/秒   共发送%3字节")
                         .arg(ReceiveCount, 10)
                         .arg(ReceiveSpeed, 10)
                         .arg(SendCount, 10));

    ui->statusbar->addPermanentWidget(DataLab);

    ui->statusbar->addPermanentWidget(TimeLab);

    UpdateTime();

    for(uint8_t i = 0; i < MAX_BAUDLIST; i++)
    {
        ui->BaudCbox->addItem(BaudList[i]);
    }
    ui->BaudCbox->setCurrentIndex(4);

    for(uint8_t i = 0; i < 4; i++)
    {
        ui->DataBitCbox->addItem(DataBitList[i]);
    }
    ui->DataBitCbox->setCurrentIndex(3);

    for(uint8_t i = 0; i < 3; i++)
    {
        ui->CheckBitCbox->addItem(CheckBitList[i]);
    }

    for(uint8_t i = 0; i < 3; i++)
    {
        ui->StopBitCbox->addItem(StopBitList[i]);
    }
    ReadConfigure();

    connect(ui->SwitchPortPbtn, SIGNAL(clicked()), this, SLOT(SwitchPort()));

    connect(ui->CleanReceivePbtn, SIGNAL(clicked()), this, SLOT(CleanReceiveData()));

    connect(ui->CleanStatsPbtn, SIGNAL(clicked()), this, SLOT(CleanStats()));

    connect(ui->CleanSendPbtn, SIGNAL(clicked()), this, SLOT(CleanSendData()));

    connect(ui->SendPbtn, SIGNAL(clicked()), this, SLOT(SendData()));

    connect(ui->TimeSendCbox, SIGNAL(stateChanged(int)), this, SLOT(AutoSend(int)));

    connect(&Ser, SIGNAL(readyRead()), this, SLOT(ReceiveData()));

    connect(&AutoSendTimer, SIGNAL(timeout()), this, SLOT(SendData()));

    connect(&RefreshPortTimer, SIGNAL(timeout()), this, SLOT(RefreshPort()));

    connect(&UpdateTimeTimer, SIGNAL(timeout()), this, SLOT(UpdateTime()));

    ui->SendTextEdit->installEventFilter(this);

    UpdateTimeTimer.start(1000);

    RefreshPortTimer.start(100);
}

/**
    * @name		~MainWindow
    * @brief  	关闭函数
  */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
    * @name		RefreshPort
    * @brief  	刷新串口列表
  */
void MainWindow::RefreshPort()
{
    if(!SwitchPortFlag)
    {
        QStringList TempPortList;
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            TempPortList << info.portName();
        }
        if(TempPortList != PortList)
        {
            PortList.clear();

            PortList = TempPortList;

            ui->PortCbox->clear();

            ui->PortCbox->addItems(PortList);
        }
    }
    else
    {
        QStringList TempPortList;
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            TempPortList << info.portName();
        }
        if(!TempPortList.contains(ui->PortCbox->currentText()))
        {
            SwitchPort();
        }
    }
}

/**
    * @name		SwitchPort
    * @brief  	串口开关函数
  */
void MainWindow::SwitchPort()
{
    WriteConfigure();

    if(!SwitchPortFlag)
    {
        if(ui->PortCbox->count() > 0)
        {
            Ser.setPortName(ui->PortCbox->currentText());

            Ser.setBaudRate(ui->BaudCbox->currentText().toInt());

            Ser.setDataBits((QSerialPort::DataBits)ui->DataBitCbox->currentText().toInt());

            uint8_t CheckBit = ui->CheckBitCbox->currentIndex();

            if(!CheckBit)
            {
                Ser.setParity((QSerialPort::NoParity));
            }
            else
            {
                Ser.setParity((QSerialPort::Parity)(CheckBit + 1));
            }
            Ser.setStopBits((QSerialPort::StopBits)ui->StopBitCbox->currentIndex());

            if(Ser.open(QIODevice::ReadWrite))
            {
                ShowMessage(ui->PortCbox->currentText() + "打开成功");

                SwitchPortFlag = true;

                ui->SwitchPortPbtn->setText("关闭串口");

                ui->PortCbox->setEnabled(false);

                ui->BaudCbox->setEnabled(false);

                ui->DataBitCbox->setEnabled(false);

                ui->CheckBitCbox->setEnabled(false);

                ui->StopBitCbox->setEnabled(false);

                Ser.clear();
            }
            else
            {
                ShowMessage(ui->PortCbox->currentText() + "打开失败");
            }
        }
        else
        {
            ShowMessage("未搜索到可用串口");
        }
    }
    else
    {
        SwitchPortFlag = false;

        ui->SwitchPortPbtn->setText("打开串口");

        ui->PortCbox->setEnabled(true);

        ui->BaudCbox->setEnabled(true);

        ui->DataBitCbox->setEnabled(true);

        ui->CheckBitCbox->setEnabled(true);

        ui->StopBitCbox->setEnabled(true);

        Ser.close();

        ShowMessage(ui->PortCbox->currentText() + "已关闭");
    }
}

/**
    * @name		CleanReceiveData
    * @brief  	清空接收数据函数
  */
void MainWindow::CleanReceiveData()
{
    ui->ReceiveTextEdit->clear();
}

/**
    * @name		CleanStats
    * @brief  	清空接收统计函数
  */
void MainWindow::CleanStats()
{
    ReceiveCount = 0;

    ReceiveLastCount = 0;

    ReceiveSpeed = 0;

    SendCount = 0;

    DataLab->setText(QString("共接收%1字节，速度%2字节/秒   共发送%3字节")
                    .arg(ReceiveCount, 10)
                    .arg(ReceiveSpeed, 10)
                    .arg(SendCount, 10));
}

/**
    * @name		CleanSendData
    * @brief  	清空发送数据函数
  */
void MainWindow::CleanSendData()
{
    ui->SendTextEdit->clear();
}

/**
    * @name		ReceiveData
    * @brief  	接收数据函数
  */
void MainWindow::ReceiveData()
{
    QByteArray Data = Ser.readAll();

    if(ui->TalkWindowCbox->isChecked())
    {
        ui->ReceiveTextEdit->append("<font color=\"#FF0000\">" + NowTime + " Receive:" + "</font>");
    }

    if(!ui->HexShowCbox->isChecked())
    {
        ui->ReceiveTextEdit->append(Data);
    }
    else
    {
        ui->ReceiveTextEdit->append(ByteArrayToHexString(Data));
    }
    if(ui->AutoFollowCbox->isChecked())
    {
        ui->ReceiveTextEdit->moveCursor(QTextCursor::End);
    }
    ReceiveCount += Data.size();
}

/**
    * @name		SendData
    * @brief  	发送数据函数
  */
void MainWindow::SendData()
{
    if(SwitchPortFlag)
    {
        QString Data = ui->SendTextEdit->toPlainText();

        if(Data.size() > 0)
        {
            if(ui->TalkWindowCbox->isChecked())
            {
                ui->ReceiveTextEdit->append("<font color=\"#00DD00\">" + NowTime + " Send:" + "</font>");

                ui->ReceiveTextEdit->append(Data);
            }

            if(ui->HexSendCbox->isChecked())
            {
                if (Data.contains(" "))
                {
                    Data.replace(QString(" "),QString(""));
                }
                QByteArray TempData = HexStringToQByteArray(Data);

                Ser.write(TempData);

                SendCount += TempData.size();
            }
            else
            {
                if(ui->AutoEnterCBox->isChecked())
                {
                    Data.append("\r\n");
                }
                Ser.write(Data.toUtf8());

                SendCount += Data.size();
            }
            if(ui->SendCleanCbox->isChecked())
            {
                CleanSendData();
            }
        }
        else
        {
            ShowMessage("请先输入数据");
        }
    }
    else
    {
        ShowMessage("请先打开串口");
    }
}

/**
    * @name		AutoSend
    * @brief  	定时发送
  */
void MainWindow::AutoSend(int state)
{
    if(state)
    {
        ui->TimeSBox->setReadOnly(true);

        uint16_t time = ui->TimeSBox->value();

        AutoSendTimer.start(time);
    }
    else
    {
        AutoSendTimer.stop();

        ui->TimeSBox->setReadOnly(false);
    }
}

/**
    * @name		WriteConfigure
    * @brief  	写入配置文件函数
  */
void MainWindow::WriteConfigure()
{
    FILE *fp = fopen(ConfigureFileName, "w");

    fprintf(fp, "[Configure]\n");

    fprintf(fp, QString("[Baud]=%1\n").arg(ui->BaudCbox->currentIndex()).toLatin1());

    fprintf(fp, QString("[DataBit]=%1\n").arg(ui->DataBitCbox->currentIndex()).toLatin1());

    fprintf(fp, QString("[CheckBit]=%1\n").arg(ui->CheckBitCbox->currentIndex()).toLatin1());

    fprintf(fp, QString("[StopBit]=%1\n").arg(ui->StopBitCbox->currentIndex()).toLatin1());

    if(ui->HexShowCbox->isChecked())
        fprintf(fp, "[HexShow]=true\n");
    else
        fprintf(fp, "[HexShow]=false\n");
    if(ui->AutoFollowCbox->isChecked())
        fprintf(fp, "[AutoFollow]=true\n");
    else
        fprintf(fp, "[AutoFollow]=false\n");
    if(ui->TalkWindowCbox->isChecked())
        fprintf(fp, "[TalkWindow]=true\n");
    else
        fprintf(fp, "[TalkWindow]=false\n");
    if(ui->HexSendCbox->isChecked())
        fprintf(fp, "[HexSend]=true\n");
    else
        fprintf(fp, "[HexSend]=false\n");
    if(ui->EnterSendCBox->isChecked())
        fprintf(fp, "[EnterSend]=true\n");
    else
        fprintf(fp, "[EnterSend]=false\n");
    if(ui->AutoEnterCBox->isChecked())
        fprintf(fp, "[AutoEnter]=true\n");
    else
        fprintf(fp, "[AutoEnter]=false\n");
    if(ui->SendCleanCbox->isChecked())
        fprintf(fp, "[SendClean]=true\n");
    else
        fprintf(fp, "[SendClean]=false\n");
    fclose(fp);
}

/**
    * @name		ReadConfigure
    * @brief  	读取配置文件函数
  */
void MainWindow::ReadConfigure()
{
    if(QFile(ConfigureFileName).exists())
    {
        FILE *fp = fopen(ConfigureFileName, "r");

        if(strcmp(ReadLineChars(fp, 0).toLatin1(), "[Configure]") == 0)
        {
            ui->BaudCbox->setCurrentIndex(ReadLineChars(fp, 1).split("=")[1].toInt());

            ui->DataBitCbox->setCurrentIndex(ReadLineChars(fp, 2).split("=")[1].toInt());

            ui->CheckBitCbox->setCurrentIndex(ReadLineChars(fp, 3).split("=")[1].toInt());

            ui->StopBitCbox->setCurrentIndex(ReadLineChars(fp, 4).split("=")[1].toInt());

            if(ReadLineChars(fp, 5).split("=")[1].toLatin1() == "true")
                ui->HexShowCbox->setChecked(true);
            else
                ui->HexShowCbox->setChecked(false);
            if(ReadLineChars(fp, 6).split("=")[1].toLatin1() == "true")
                ui->AutoFollowCbox->setChecked(true);
            else
                ui->AutoFollowCbox->setChecked(false);
            if(ReadLineChars(fp, 7).split("=")[1].toLatin1() == "true")
                ui->TalkWindowCbox->setChecked(true);
            else
                ui->TalkWindowCbox->setChecked(false);
            if(ReadLineChars(fp, 8).split("=")[1].toLatin1() == "true")
                ui->HexSendCbox->setChecked(true);
            else
                ui->HexSendCbox->setChecked(false);
            if(ReadLineChars(fp, 9).split("=")[1].toLatin1() == "true")
                ui->EnterSendCBox->setChecked(true);
            else
                ui->EnterSendCBox->setChecked(false);
            if(ReadLineChars(fp, 10).split("=")[1].toLatin1() == "true")
                ui->AutoEnterCBox->setChecked(true);
            else
                ui->AutoEnterCBox->setChecked(false);
            if(ReadLineChars(fp, 11).split("=")[1].toLatin1() == "true")
                ui->SendCleanCbox->setChecked(true);
            else
                ui->SendCleanCbox->setChecked(false);
        }
    }
}

/**
    * @name		eventFilter
    * @brief  	事件过滤器
  */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->SendTextEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
             QKeyEvent *k = static_cast<QKeyEvent *>(event);

             if(k->key() == Qt::Key_Return || k->key() == Qt::Key_Enter)
             {
                 if(ui->EnterSendCBox->isChecked())
                 {
                    SendData();
                 }
                 return true;
             }
        }
    }
    return false;
}

/**
    * @name		UpdateTime
    * @brief  	更新时间函数
  */
void MainWindow::UpdateTime()
{
    time_t nowtime;

    struct tm* p;

    time(&nowtime);

    p = localtime(&nowtime);

    NowTime = QString("%1:%2:%3").arg(p->tm_hour, 2, 10, QLatin1Char('0'))
            .arg(p->tm_min, 2, 10, QLatin1Char('0'))
            .arg(p->tm_sec, 2, 10, QLatin1Char('0'));

    TimeLab->setText("当前时间：" + NowTime);

    ReceiveSpeed = ReceiveCount - ReceiveLastCount;

    ReceiveLastCount = ReceiveCount;

    DataLab->setText(QString("共接收%1字节，速度%2字节/秒   共发送%3字节")
                    .arg(ReceiveCount, 10)
                    .arg(ReceiveSpeed, 10)
                    .arg(SendCount, 10));
}

/**
    * @name		ShowMessage
    * @brief  	显示消息函数
  */
void MainWindow::ShowMessage(QString Message)
{
    ui->statusbar->showMessage(Message, 1500);
}

/**
    * @name		ByteArrayToHexString
    * @brief  	QByteArray转QString
  */
QString ByteArrayToHexString(QByteArray ascii)
{
    QString ret;
    for(int i = 0; i < ascii.count(); i++)
    {
        ret.append(QString("%1 ").arg((uchar)ascii.at(i), 2, 16, (QChar)'0'));
    }
    return ret.toUpper();
}

/**
    * @name		HexStringToQByteArray
    * @brief  	Hex字符串转QByteArray
  */
QByteArray HexStringToQByteArray(QString str)
{
    int hexdata,lowhexdata;

    int hexdatalen = 0;

    int len = str.length();

    QByteArray byteData;

    byteData.resize(len/2);

    char lstr,hstr;

    for(int i = 0; i < len; i++)
    {
        hstr=str[i].toLatin1();

        if(hstr == ' ')
        {
            i++;

            continue;
        }
        i++;

        if(i >= len)
            break;

        lstr = str[i].toLatin1();

        hexdata = ConvertCharToHex(hstr);

        lowhexdata = ConvertCharToHex(lstr);

        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = (hexdata << 4) + lowhexdata;

        byteData[hexdatalen] = (char)hexdata;

        hexdatalen++;
    }
    byteData.resize(hexdatalen);

    return byteData;
}

/**
    * @name		ConvertCharToHex
    * @brief  	char 转为 16进制
  */
char ConvertCharToHex(char ch)
{
    /*
        0x30等于十进制的48，48也是0的ASCII值，，
        1-9的ASCII值是49-57，，所以某一个值－0x30，，
        就是将字符0-9转换为0-9
    */
    if((ch >= '0') && (ch <= '9'))
         return ch-0x30;
     else if((ch >= 'A') && (ch <= 'F'))
         return ch-'A'+10;
     else if((ch >= 'a') && (ch <= 'f'))
         return ch-'a'+10;
     else return (-1);
}

/**
    * @name		ReadLineChars
    * @brief  	读取目标行文件内容
  */
QString ReadLineChars(FILE* fp, uint32_t line)
{
    uint32_t i;

    char buf[128];

    for(i = 0; i <= line; i++)
    {
        fgets(buf, 128, fp);

        if(i == line)
        {
            if(buf[strlen(buf) - 1] == '\n')
            {
                buf[strlen(buf) - 1] = '\0';
            }
            fseek(fp, 0L,SEEK_SET);

            return QString(buf);
        }
    }
    return "error";
}

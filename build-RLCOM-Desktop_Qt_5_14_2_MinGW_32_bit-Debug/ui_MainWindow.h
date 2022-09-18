/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QLabel *LogoLab;
    QTabWidget *TabWidget;
    QWidget *Tab1;
    QVBoxLayout *verticalLayout;
    QGroupBox *ReceiveGbox;
    QGridLayout *gridLayout_2;
    QCheckBox *HexShowCbox;
    QPushButton *CleanReceivePbtn;
    QCheckBox *TalkWindowCbox;
    QPushButton *CleanStatsPbtn;
    QCheckBox *AutoFollowCbox;
    QTextEdit *ReceiveTextEdit;
    QGroupBox *SendGbox;
    QGridLayout *gridLayout_3;
    QPushButton *SendPbtn;
    QCheckBox *EnterSendCBox;
    QSpinBox *TimeSBox;
    QPushButton *CleanSendPbtn;
    QCheckBox *AutoEnterCBox;
    QCheckBox *TimeSendCbox;
    QCheckBox *HexSendCbox;
    QCheckBox *SendCleanCbox;
    QTextEdit *SendTextEdit;
    QWidget *Tab2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QCheckBox *GridCbox;
    QSpacerItem *verticalSpacer_2;
    QLabel *WidthLab;
    QLineEdit *WidthLedit;
    QPushButton *SwitchImagePbtn;
    QComboBox *ImageModeCBox;
    QLineEdit *HeightLedit;
    QLabel *HeightLab;
    QGroupBox *ImageGbox;
    QVBoxLayout *verticalLayout_2;
    QLabel *ImageLab;
    QWidget *Tab3;
    QGridLayout *gridLayout_7;
    QGroupBox *WaveformConfigure;
    QGridLayout *gridLayout_8;
    QComboBox *DataTypeCbox;
    QSpinBox *ChannleSbox;
    QPushButton *SwitchWaveformPbtn;
    QLabel *DataTypeLab;
    QLabel *ChannleLab;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *ChartConfigure;
    QGridLayout *gridLayout_6;
    QPushButton *YaxisZoomPbtn;
    QCheckBox *ChartAutoFollowCbox;
    QPushButton *XaxisZoomPbtn;
    QCheckBox *AdaptiveCbox;
    QPushButton *XaxisShrinkPbtn;
    QPushButton *YaxisShrinkPbtn;
    QPushButton *YaxisZeroPbtn;
    QCustomPlot *ChartWidget;
    QGroupBox *ProtConfigure;
    QGridLayout *gridLayout;
    QLabel *DataBitLab;
    QLabel *BaudLab;
    QComboBox *BaudCbox;
    QLabel *CheckBitLab;
    QComboBox *DataBitCbox;
    QComboBox *CheckBitCbox;
    QComboBox *PortCbox;
    QComboBox *StopBitCbox;
    QLabel *StopBitLab;
    QPushButton *SwitchPortPbtn;
    QLabel *PortLab;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        LogoLab = new QLabel(centralwidget);
        LogoLab->setObjectName(QString::fromUtf8("LogoLab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(200);
        sizePolicy.setHeightForWidth(LogoLab->sizePolicy().hasHeightForWidth());
        LogoLab->setSizePolicy(sizePolicy);
        LogoLab->setMaximumSize(QSize(200, 200));
        LogoLab->setAutoFillBackground(false);
        LogoLab->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        LogoLab->setScaledContents(true);

        gridLayout_4->addWidget(LogoLab, 0, 0, 1, 1);

        TabWidget = new QTabWidget(centralwidget);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        Tab1 = new QWidget();
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        verticalLayout = new QVBoxLayout(Tab1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ReceiveGbox = new QGroupBox(Tab1);
        ReceiveGbox->setObjectName(QString::fromUtf8("ReceiveGbox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(7);
        sizePolicy1.setHeightForWidth(ReceiveGbox->sizePolicy().hasHeightForWidth());
        ReceiveGbox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(ReceiveGbox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        HexShowCbox = new QCheckBox(ReceiveGbox);
        HexShowCbox->setObjectName(QString::fromUtf8("HexShowCbox"));

        gridLayout_2->addWidget(HexShowCbox, 1, 0, 1, 1);

        CleanReceivePbtn = new QPushButton(ReceiveGbox);
        CleanReceivePbtn->setObjectName(QString::fromUtf8("CleanReceivePbtn"));

        gridLayout_2->addWidget(CleanReceivePbtn, 1, 3, 1, 1);

        TalkWindowCbox = new QCheckBox(ReceiveGbox);
        TalkWindowCbox->setObjectName(QString::fromUtf8("TalkWindowCbox"));

        gridLayout_2->addWidget(TalkWindowCbox, 1, 2, 1, 1);

        CleanStatsPbtn = new QPushButton(ReceiveGbox);
        CleanStatsPbtn->setObjectName(QString::fromUtf8("CleanStatsPbtn"));

        gridLayout_2->addWidget(CleanStatsPbtn, 1, 4, 1, 1);

        AutoFollowCbox = new QCheckBox(ReceiveGbox);
        AutoFollowCbox->setObjectName(QString::fromUtf8("AutoFollowCbox"));

        gridLayout_2->addWidget(AutoFollowCbox, 1, 1, 1, 1);

        ReceiveTextEdit = new QTextEdit(ReceiveGbox);
        ReceiveTextEdit->setObjectName(QString::fromUtf8("ReceiveTextEdit"));
        ReceiveTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        ReceiveTextEdit->setReadOnly(true);
        ReceiveTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(ReceiveTextEdit, 0, 0, 1, 5);


        verticalLayout->addWidget(ReceiveGbox);

        SendGbox = new QGroupBox(Tab1);
        SendGbox->setObjectName(QString::fromUtf8("SendGbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(3);
        sizePolicy2.setHeightForWidth(SendGbox->sizePolicy().hasHeightForWidth());
        SendGbox->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(SendGbox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SendPbtn = new QPushButton(SendGbox);
        SendPbtn->setObjectName(QString::fromUtf8("SendPbtn"));

        gridLayout_3->addWidget(SendPbtn, 1, 7, 1, 1);

        EnterSendCBox = new QCheckBox(SendGbox);
        EnterSendCBox->setObjectName(QString::fromUtf8("EnterSendCBox"));

        gridLayout_3->addWidget(EnterSendCBox, 1, 1, 1, 1);

        TimeSBox = new QSpinBox(SendGbox);
        TimeSBox->setObjectName(QString::fromUtf8("TimeSBox"));
        TimeSBox->setMinimum(1);
        TimeSBox->setMaximum(5000);
        TimeSBox->setValue(1);

        gridLayout_3->addWidget(TimeSBox, 1, 5, 1, 1);

        CleanSendPbtn = new QPushButton(SendGbox);
        CleanSendPbtn->setObjectName(QString::fromUtf8("CleanSendPbtn"));

        gridLayout_3->addWidget(CleanSendPbtn, 1, 6, 1, 1);

        AutoEnterCBox = new QCheckBox(SendGbox);
        AutoEnterCBox->setObjectName(QString::fromUtf8("AutoEnterCBox"));

        gridLayout_3->addWidget(AutoEnterCBox, 1, 2, 1, 1);

        TimeSendCbox = new QCheckBox(SendGbox);
        TimeSendCbox->setObjectName(QString::fromUtf8("TimeSendCbox"));

        gridLayout_3->addWidget(TimeSendCbox, 1, 4, 1, 1);

        HexSendCbox = new QCheckBox(SendGbox);
        HexSendCbox->setObjectName(QString::fromUtf8("HexSendCbox"));

        gridLayout_3->addWidget(HexSendCbox, 1, 0, 1, 1);

        SendCleanCbox = new QCheckBox(SendGbox);
        SendCleanCbox->setObjectName(QString::fromUtf8("SendCleanCbox"));

        gridLayout_3->addWidget(SendCleanCbox, 1, 3, 1, 1);

        SendTextEdit = new QTextEdit(SendGbox);
        SendTextEdit->setObjectName(QString::fromUtf8("SendTextEdit"));
        SendTextEdit->setAcceptRichText(false);

        gridLayout_3->addWidget(SendTextEdit, 0, 0, 1, 8);


        verticalLayout->addWidget(SendGbox);

        TabWidget->addTab(Tab1, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName(QString::fromUtf8("Tab2"));
        horizontalLayout = new QHBoxLayout(Tab2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(Tab2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setMaximumSize(QSize(200, 16777215));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(20);
        GridCbox = new QCheckBox(groupBox);
        GridCbox->setObjectName(QString::fromUtf8("GridCbox"));

        gridLayout_5->addWidget(GridCbox, 3, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 5, 0, 1, 2);

        WidthLab = new QLabel(groupBox);
        WidthLab->setObjectName(QString::fromUtf8("WidthLab"));

        gridLayout_5->addWidget(WidthLab, 2, 0, 1, 1);

        WidthLedit = new QLineEdit(groupBox);
        WidthLedit->setObjectName(QString::fromUtf8("WidthLedit"));
        WidthLedit->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(WidthLedit, 2, 1, 1, 1);

        SwitchImagePbtn = new QPushButton(groupBox);
        SwitchImagePbtn->setObjectName(QString::fromUtf8("SwitchImagePbtn"));

        gridLayout_5->addWidget(SwitchImagePbtn, 4, 0, 1, 2);

        ImageModeCBox = new QComboBox(groupBox);
        ImageModeCBox->addItem(QString());
        ImageModeCBox->addItem(QString());
        ImageModeCBox->setObjectName(QString::fromUtf8("ImageModeCBox"));

        gridLayout_5->addWidget(ImageModeCBox, 0, 0, 1, 2);

        HeightLedit = new QLineEdit(groupBox);
        HeightLedit->setObjectName(QString::fromUtf8("HeightLedit"));
        HeightLedit->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(HeightLedit, 1, 1, 1, 1);

        HeightLab = new QLabel(groupBox);
        HeightLab->setObjectName(QString::fromUtf8("HeightLab"));

        gridLayout_5->addWidget(HeightLab, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        ImageGbox = new QGroupBox(Tab2);
        ImageGbox->setObjectName(QString::fromUtf8("ImageGbox"));
        verticalLayout_2 = new QVBoxLayout(ImageGbox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ImageLab = new QLabel(ImageGbox);
        ImageLab->setObjectName(QString::fromUtf8("ImageLab"));
        ImageLab->setScaledContents(true);
        ImageLab->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ImageLab);


        horizontalLayout->addWidget(ImageGbox);

        TabWidget->addTab(Tab2, QString());
        Tab3 = new QWidget();
        Tab3->setObjectName(QString::fromUtf8("Tab3"));
        gridLayout_7 = new QGridLayout(Tab3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        WaveformConfigure = new QGroupBox(Tab3);
        WaveformConfigure->setObjectName(QString::fromUtf8("WaveformConfigure"));
        WaveformConfigure->setMinimumSize(QSize(200, 0));
        WaveformConfigure->setMaximumSize(QSize(200, 16777215));
        gridLayout_8 = new QGridLayout(WaveformConfigure);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(20);
        DataTypeCbox = new QComboBox(WaveformConfigure);
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->addItem(QString());
        DataTypeCbox->setObjectName(QString::fromUtf8("DataTypeCbox"));

        gridLayout_8->addWidget(DataTypeCbox, 1, 1, 1, 1);

        ChannleSbox = new QSpinBox(WaveformConfigure);
        ChannleSbox->setObjectName(QString::fromUtf8("ChannleSbox"));
        ChannleSbox->setMinimum(1);
        ChannleSbox->setMaximum(8);

        gridLayout_8->addWidget(ChannleSbox, 0, 1, 1, 1);

        SwitchWaveformPbtn = new QPushButton(WaveformConfigure);
        SwitchWaveformPbtn->setObjectName(QString::fromUtf8("SwitchWaveformPbtn"));

        gridLayout_8->addWidget(SwitchWaveformPbtn, 2, 0, 1, 2);

        DataTypeLab = new QLabel(WaveformConfigure);
        DataTypeLab->setObjectName(QString::fromUtf8("DataTypeLab"));

        gridLayout_8->addWidget(DataTypeLab, 1, 0, 1, 1);

        ChannleLab = new QLabel(WaveformConfigure);
        ChannleLab->setObjectName(QString::fromUtf8("ChannleLab"));

        gridLayout_8->addWidget(ChannleLab, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_3, 3, 0, 1, 2);


        gridLayout_7->addWidget(WaveformConfigure, 0, 0, 2, 1);

        ChartConfigure = new QGroupBox(Tab3);
        ChartConfigure->setObjectName(QString::fromUtf8("ChartConfigure"));
        ChartConfigure->setMinimumSize(QSize(0, 100));
        ChartConfigure->setMaximumSize(QSize(16777215, 100));
        gridLayout_6 = new QGridLayout(ChartConfigure);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        YaxisZoomPbtn = new QPushButton(ChartConfigure);
        YaxisZoomPbtn->setObjectName(QString::fromUtf8("YaxisZoomPbtn"));

        gridLayout_6->addWidget(YaxisZoomPbtn, 0, 0, 1, 1);

        ChartAutoFollowCbox = new QCheckBox(ChartConfigure);
        ChartAutoFollowCbox->setObjectName(QString::fromUtf8("ChartAutoFollowCbox"));

        gridLayout_6->addWidget(ChartAutoFollowCbox, 0, 6, 1, 1);

        XaxisZoomPbtn = new QPushButton(ChartConfigure);
        XaxisZoomPbtn->setObjectName(QString::fromUtf8("XaxisZoomPbtn"));

        gridLayout_6->addWidget(XaxisZoomPbtn, 0, 3, 1, 1);

        AdaptiveCbox = new QCheckBox(ChartConfigure);
        AdaptiveCbox->setObjectName(QString::fromUtf8("AdaptiveCbox"));

        gridLayout_6->addWidget(AdaptiveCbox, 0, 5, 1, 1);

        XaxisShrinkPbtn = new QPushButton(ChartConfigure);
        XaxisShrinkPbtn->setObjectName(QString::fromUtf8("XaxisShrinkPbtn"));

        gridLayout_6->addWidget(XaxisShrinkPbtn, 0, 4, 1, 1);

        YaxisShrinkPbtn = new QPushButton(ChartConfigure);
        YaxisShrinkPbtn->setObjectName(QString::fromUtf8("YaxisShrinkPbtn"));

        gridLayout_6->addWidget(YaxisShrinkPbtn, 0, 1, 1, 1);

        YaxisZeroPbtn = new QPushButton(ChartConfigure);
        YaxisZeroPbtn->setObjectName(QString::fromUtf8("YaxisZeroPbtn"));

        gridLayout_6->addWidget(YaxisZeroPbtn, 0, 2, 1, 1);


        gridLayout_7->addWidget(ChartConfigure, 0, 1, 1, 1);

        ChartWidget = new QCustomPlot(Tab3);
        ChartWidget->setObjectName(QString::fromUtf8("ChartWidget"));

        gridLayout_7->addWidget(ChartWidget, 1, 1, 1, 1);

        TabWidget->addTab(Tab3, QString());

        gridLayout_4->addWidget(TabWidget, 0, 1, 2, 1);

        ProtConfigure = new QGroupBox(centralwidget);
        ProtConfigure->setObjectName(QString::fromUtf8("ProtConfigure"));
        ProtConfigure->setMinimumSize(QSize(200, 0));
        ProtConfigure->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(ProtConfigure);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(20);
        DataBitLab = new QLabel(ProtConfigure);
        DataBitLab->setObjectName(QString::fromUtf8("DataBitLab"));

        gridLayout->addWidget(DataBitLab, 2, 0, 1, 1);

        BaudLab = new QLabel(ProtConfigure);
        BaudLab->setObjectName(QString::fromUtf8("BaudLab"));

        gridLayout->addWidget(BaudLab, 1, 0, 1, 1);

        BaudCbox = new QComboBox(ProtConfigure);
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->addItem(QString());
        BaudCbox->setObjectName(QString::fromUtf8("BaudCbox"));

        gridLayout->addWidget(BaudCbox, 1, 1, 1, 1);

        CheckBitLab = new QLabel(ProtConfigure);
        CheckBitLab->setObjectName(QString::fromUtf8("CheckBitLab"));

        gridLayout->addWidget(CheckBitLab, 3, 0, 1, 1);

        DataBitCbox = new QComboBox(ProtConfigure);
        DataBitCbox->addItem(QString());
        DataBitCbox->addItem(QString());
        DataBitCbox->addItem(QString());
        DataBitCbox->addItem(QString());
        DataBitCbox->setObjectName(QString::fromUtf8("DataBitCbox"));

        gridLayout->addWidget(DataBitCbox, 2, 1, 1, 1);

        CheckBitCbox = new QComboBox(ProtConfigure);
        CheckBitCbox->addItem(QString());
        CheckBitCbox->addItem(QString());
        CheckBitCbox->addItem(QString());
        CheckBitCbox->setObjectName(QString::fromUtf8("CheckBitCbox"));

        gridLayout->addWidget(CheckBitCbox, 3, 1, 1, 1);

        PortCbox = new QComboBox(ProtConfigure);
        PortCbox->setObjectName(QString::fromUtf8("PortCbox"));

        gridLayout->addWidget(PortCbox, 0, 1, 1, 1);

        StopBitCbox = new QComboBox(ProtConfigure);
        StopBitCbox->addItem(QString());
        StopBitCbox->addItem(QString());
        StopBitCbox->addItem(QString());
        StopBitCbox->setObjectName(QString::fromUtf8("StopBitCbox"));

        gridLayout->addWidget(StopBitCbox, 4, 1, 1, 1);

        StopBitLab = new QLabel(ProtConfigure);
        StopBitLab->setObjectName(QString::fromUtf8("StopBitLab"));

        gridLayout->addWidget(StopBitLab, 4, 0, 1, 1);

        SwitchPortPbtn = new QPushButton(ProtConfigure);
        SwitchPortPbtn->setObjectName(QString::fromUtf8("SwitchPortPbtn"));

        gridLayout->addWidget(SwitchPortPbtn, 5, 0, 1, 2);

        PortLab = new QLabel(ProtConfigure);
        PortLab->setObjectName(QString::fromUtf8("PortLab"));

        gridLayout->addWidget(PortLab, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 2);


        gridLayout_4->addWidget(ProtConfigure, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        TabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RLCOM", nullptr));
        LogoLab->setText(QString());
        ReceiveGbox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        HexShowCbox->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        CleanReceivePbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        TalkWindowCbox->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235\345\274\217\347\252\227\345\217\243", nullptr));
        CleanStatsPbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\273\237\350\256\241", nullptr));
        AutoFollowCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\267\237\350\270\252", nullptr));
        SendGbox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        SendPbtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        EnterSendCBox->setText(QCoreApplication::translate("MainWindow", "\345\233\236\350\275\246\351\224\256\345\217\221\351\200\201", nullptr));
        CleanSendPbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        AutoEnterCBox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        TimeSendCbox->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201\357\274\210\345\215\225\344\275\215ms\357\274\211", nullptr));
        HexSendCbox->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        SendCleanCbox->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\220\216\346\270\205\351\231\244", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab1), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\224\266\345\217\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\351\205\215\347\275\256", nullptr));
        GridCbox->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\240\205\346\240\274", nullptr));
        WidthLab->setText(QCoreApplication::translate("MainWindow", "Width\357\274\232", nullptr));
        WidthLedit->setText(QString());
        SwitchImagePbtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\216\245\346\224\266", nullptr));
        ImageModeCBox->setItemText(0, QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\345\233\276", nullptr));
        ImageModeCBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\345\233\276", nullptr));

        HeightLab->setText(QCoreApplication::translate("MainWindow", "Height\357\274\232", nullptr));
        ImageGbox->setTitle(QCoreApplication::translate("MainWindow", "Image", nullptr));
        ImageLab->setText(QCoreApplication::translate("MainWindow", "Waiting......", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab2), QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\344\274\240\350\276\223", nullptr));
        WaveformConfigure->setTitle(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\242\351\205\215\347\275\256", nullptr));
        DataTypeCbox->setItemText(0, QCoreApplication::translate("MainWindow", "uint8", nullptr));
        DataTypeCbox->setItemText(1, QCoreApplication::translate("MainWindow", "uint16", nullptr));
        DataTypeCbox->setItemText(2, QCoreApplication::translate("MainWindow", "uint32", nullptr));
        DataTypeCbox->setItemText(3, QCoreApplication::translate("MainWindow", "int8", nullptr));
        DataTypeCbox->setItemText(4, QCoreApplication::translate("MainWindow", "int16", nullptr));
        DataTypeCbox->setItemText(5, QCoreApplication::translate("MainWindow", "int32", nullptr));
        DataTypeCbox->setItemText(6, QCoreApplication::translate("MainWindow", "float", nullptr));
        DataTypeCbox->setItemText(7, QCoreApplication::translate("MainWindow", "double", nullptr));

        SwitchWaveformPbtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\216\245\346\224\266", nullptr));
        DataTypeLab->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        ChannleLab->setText(QCoreApplication::translate("MainWindow", "\351\200\232\351\201\223\346\225\260\357\274\232", nullptr));
        ChartConfigure->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\350\241\250\351\205\215\347\275\256", nullptr));
        YaxisZoomPbtn->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\346\224\276\345\244\247", nullptr));
        ChartAutoFollowCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\267\237\350\270\252", nullptr));
        XaxisZoomPbtn->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\346\224\276\345\244\247", nullptr));
        AdaptiveCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\351\200\202\345\272\224\347\252\227\345\217\243", nullptr));
        XaxisShrinkPbtn->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\347\274\251\345\260\217", nullptr));
        YaxisShrinkPbtn->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\347\274\251\345\260\217", nullptr));
        YaxisZeroPbtn->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\345\275\2220", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab3), QCoreApplication::translate("MainWindow", "\350\231\232\346\213\237\347\244\272\346\263\242", nullptr));
        ProtConfigure->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        DataBitLab->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        BaudLab->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudCbox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudCbox->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        BaudCbox->setItemText(2, QCoreApplication::translate("MainWindow", "38400", nullptr));
        BaudCbox->setItemText(3, QCoreApplication::translate("MainWindow", "57600", nullptr));
        BaudCbox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));
        BaudCbox->setItemText(5, QCoreApplication::translate("MainWindow", "460800", nullptr));
        BaudCbox->setItemText(6, QCoreApplication::translate("MainWindow", "500000", nullptr));
        BaudCbox->setItemText(7, QCoreApplication::translate("MainWindow", "576000", nullptr));
        BaudCbox->setItemText(8, QCoreApplication::translate("MainWindow", "921600", nullptr));
        BaudCbox->setItemText(9, QCoreApplication::translate("MainWindow", "1000000", nullptr));
        BaudCbox->setItemText(10, QCoreApplication::translate("MainWindow", "1152000", nullptr));
        BaudCbox->setItemText(11, QCoreApplication::translate("MainWindow", "1500000", nullptr));
        BaudCbox->setItemText(12, QCoreApplication::translate("MainWindow", "2000000", nullptr));
        BaudCbox->setItemText(13, QCoreApplication::translate("MainWindow", "2500000", nullptr));
        BaudCbox->setItemText(14, QCoreApplication::translate("MainWindow", "3000000", nullptr));
        BaudCbox->setItemText(15, QCoreApplication::translate("MainWindow", "3500000", nullptr));
        BaudCbox->setItemText(16, QCoreApplication::translate("MainWindow", "4000000", nullptr));

        CheckBitLab->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        DataBitCbox->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        DataBitCbox->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        DataBitCbox->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        DataBitCbox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        CheckBitCbox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\240\241\351\252\214", nullptr));
        CheckBitCbox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));
        CheckBitCbox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));

        StopBitCbox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBitCbox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        StopBitCbox->setItemText(2, QCoreApplication::translate("MainWindow", "1.5", nullptr));

        StopBitLab->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        SwitchPortPbtn->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        PortLab->setText(QCoreApplication::translate("MainWindow", "\347\253\257  \345\217\243\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

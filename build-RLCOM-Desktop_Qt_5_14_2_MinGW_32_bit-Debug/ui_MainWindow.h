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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
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
    QGroupBox *SendGbox;
    QGridLayout *gridLayout_3;
    QPushButton *SendPbtn;
    QSpinBox *TimeSBox;
    QPushButton *CleanSendPbtn;
    QCheckBox *TimeSendCbox;
    QCheckBox *HexSendCbox;
    QPlainTextEdit *SendPlainTextEdit;
    QGroupBox *ReceiveGbox;
    QGridLayout *gridLayout_2;
    QCheckBox *HexShowCbox;
    QPushButton *CleanReceivePbtn;
    QCheckBox *TalkWindowCbox;
    QPushButton *CleanStatsPbtn;
    QCheckBox *AutoFollowCbox;
    QTextEdit *ReceiveTextEdit;
    QLabel *LogoLab;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
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
        BaudCbox->setObjectName(QString::fromUtf8("BaudCbox"));

        gridLayout->addWidget(BaudCbox, 1, 1, 1, 1);

        CheckBitLab = new QLabel(ProtConfigure);
        CheckBitLab->setObjectName(QString::fromUtf8("CheckBitLab"));

        gridLayout->addWidget(CheckBitLab, 3, 0, 1, 1);

        DataBitCbox = new QComboBox(ProtConfigure);
        DataBitCbox->setObjectName(QString::fromUtf8("DataBitCbox"));

        gridLayout->addWidget(DataBitCbox, 2, 1, 1, 1);

        CheckBitCbox = new QComboBox(ProtConfigure);
        CheckBitCbox->setObjectName(QString::fromUtf8("CheckBitCbox"));

        gridLayout->addWidget(CheckBitCbox, 3, 1, 1, 1);

        PortCbox = new QComboBox(ProtConfigure);
        PortCbox->setObjectName(QString::fromUtf8("PortCbox"));

        gridLayout->addWidget(PortCbox, 0, 1, 1, 1);

        StopBitCbox = new QComboBox(ProtConfigure);
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


        gridLayout_4->addWidget(ProtConfigure, 1, 0, 2, 1);

        SendGbox = new QGroupBox(centralwidget);
        SendGbox->setObjectName(QString::fromUtf8("SendGbox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(SendGbox->sizePolicy().hasHeightForWidth());
        SendGbox->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(SendGbox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SendPbtn = new QPushButton(SendGbox);
        SendPbtn->setObjectName(QString::fromUtf8("SendPbtn"));

        gridLayout_3->addWidget(SendPbtn, 1, 4, 1, 1);

        TimeSBox = new QSpinBox(SendGbox);
        TimeSBox->setObjectName(QString::fromUtf8("TimeSBox"));

        gridLayout_3->addWidget(TimeSBox, 1, 2, 1, 1);

        CleanSendPbtn = new QPushButton(SendGbox);
        CleanSendPbtn->setObjectName(QString::fromUtf8("CleanSendPbtn"));

        gridLayout_3->addWidget(CleanSendPbtn, 1, 3, 1, 1);

        TimeSendCbox = new QCheckBox(SendGbox);
        TimeSendCbox->setObjectName(QString::fromUtf8("TimeSendCbox"));

        gridLayout_3->addWidget(TimeSendCbox, 1, 1, 1, 1);

        HexSendCbox = new QCheckBox(SendGbox);
        HexSendCbox->setObjectName(QString::fromUtf8("HexSendCbox"));

        gridLayout_3->addWidget(HexSendCbox, 1, 0, 1, 1);

        SendPlainTextEdit = new QPlainTextEdit(SendGbox);
        SendPlainTextEdit->setObjectName(QString::fromUtf8("SendPlainTextEdit"));
        SendPlainTextEdit->setReadOnly(false);

        gridLayout_3->addWidget(SendPlainTextEdit, 0, 0, 1, 5);


        gridLayout_4->addWidget(SendGbox, 2, 1, 1, 1);

        ReceiveGbox = new QGroupBox(centralwidget);
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


        gridLayout_4->addWidget(ReceiveGbox, 0, 1, 2, 1);

        LogoLab = new QLabel(centralwidget);
        LogoLab->setObjectName(QString::fromUtf8("LogoLab"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(200);
        sizePolicy2.setVerticalStretch(200);
        sizePolicy2.setHeightForWidth(LogoLab->sizePolicy().hasHeightForWidth());
        LogoLab->setSizePolicy(sizePolicy2);
        LogoLab->setMaximumSize(QSize(200, 200));
        LogoLab->setAutoFillBackground(false);
        LogoLab->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        LogoLab->setScaledContents(true);

        gridLayout_4->addWidget(LogoLab, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RLCOM", nullptr));
        ProtConfigure->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        DataBitLab->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        BaudLab->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        CheckBitLab->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        StopBitLab->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        SwitchPortPbtn->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        PortLab->setText(QCoreApplication::translate("MainWindow", "\347\253\257  \345\217\243\357\274\232", nullptr));
        SendGbox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        SendPbtn->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        CleanSendPbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        TimeSendCbox->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201\357\274\210\345\215\225\344\275\215ms\357\274\211", nullptr));
        HexSendCbox->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        ReceiveGbox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        HexShowCbox->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        CleanReceivePbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        TalkWindowCbox->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235\345\274\217\347\252\227\345\217\243", nullptr));
        CleanStatsPbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\273\237\350\256\241", nullptr));
        AutoFollowCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\267\237\350\270\252", nullptr));
        LogoLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

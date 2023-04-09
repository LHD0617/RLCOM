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
    QGroupBox *ProtConfigure;
    QGridLayout *gridLayout;
    QComboBox *CheckBitCbox;
    QSpacerItem *verticalSpacer;
    QLabel *BaudLab;
    QPushButton *SwitchPortPbtn;
    QComboBox *StopBitCbox;
    QComboBox *BaudCbox;
    QLabel *CheckBitLab;
    QComboBox *DataBitCbox;
    QComboBox *PortCbox;
    QLabel *StopBitLab;
    QLabel *DataBitLab;
    QLabel *PortLab;
    QPushButton *CleanStatsPbtn;
    QTabWidget *TabWidget;
    QWidget *Tab1;
    QVBoxLayout *verticalLayout;
    QGroupBox *ReceiveGbox;
    QGridLayout *gridLayout_2;
    QCheckBox *HexShowCbox;
    QCheckBox *AutoFollowCbox;
    QCheckBox *TalkWindowCbox;
    QPushButton *CleanReceivePbtn;
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
    QCustomPlot *ChartWidget;
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
    QCheckBox *AdaptiveCbox;
    QCheckBox *ChartAutoFollowCbox;
    QPushButton *XaxisZoomPbtn;
    QPushButton *XaxisShrinkPbtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #3"
                        "43434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b"
                        "1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QToolButton\n"
"{\n"
"	border-style:solid;\n"
"	color: #b1b1b1;\n"
"	padding:5px;\n"
"	min-height:15px;\n"
"	border-radius:0px;\n"
"	background:#323232;\n"
"}\n"
"\n"
"QToolButton:hover\n"
"{\n"
"	border-bottom-width:2;\n"
"	background-color: #282828;\n"
"	border-bottom-color:#d7801a;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border-bottom-width:2;\n"
"	border-bottom-color:#ffa02f;\n"
"	background-color: #282828;\n"
"	border-radius:0px;\n"
"}"
                        "\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
""
                        "{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/icon/combobox.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{"
                        "\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"Q"
                        "ScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
" "
                        "     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: cen"
                        "ter;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between ite"
                        "ms in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/icon/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: #d7801a;\n"
"    width: 2.15px;\n"
"    marg"
                        "in: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
""
                        "    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
""
                        "    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/icon/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
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
        LogoLab->setPixmap(QPixmap(QString::fromUtf8(":/icon/logo.png")));
        LogoLab->setScaledContents(true);

        gridLayout_4->addWidget(LogoLab, 0, 0, 1, 1);

        ProtConfigure = new QGroupBox(centralwidget);
        ProtConfigure->setObjectName(QString::fromUtf8("ProtConfigure"));
        ProtConfigure->setMinimumSize(QSize(200, 0));
        ProtConfigure->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(ProtConfigure);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(20);
        CheckBitCbox = new QComboBox(ProtConfigure);
        CheckBitCbox->addItem(QString());
        CheckBitCbox->addItem(QString());
        CheckBitCbox->addItem(QString());
        CheckBitCbox->setObjectName(QString::fromUtf8("CheckBitCbox"));

        gridLayout->addWidget(CheckBitCbox, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 2);

        BaudLab = new QLabel(ProtConfigure);
        BaudLab->setObjectName(QString::fromUtf8("BaudLab"));

        gridLayout->addWidget(BaudLab, 1, 0, 1, 1);

        SwitchPortPbtn = new QPushButton(ProtConfigure);
        SwitchPortPbtn->setObjectName(QString::fromUtf8("SwitchPortPbtn"));

        gridLayout->addWidget(SwitchPortPbtn, 5, 0, 1, 2);

        StopBitCbox = new QComboBox(ProtConfigure);
        StopBitCbox->addItem(QString());
        StopBitCbox->addItem(QString());
        StopBitCbox->addItem(QString());
        StopBitCbox->setObjectName(QString::fromUtf8("StopBitCbox"));

        gridLayout->addWidget(StopBitCbox, 4, 1, 1, 1);

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

        PortCbox = new QComboBox(ProtConfigure);
        PortCbox->setObjectName(QString::fromUtf8("PortCbox"));

        gridLayout->addWidget(PortCbox, 0, 1, 1, 1);

        StopBitLab = new QLabel(ProtConfigure);
        StopBitLab->setObjectName(QString::fromUtf8("StopBitLab"));

        gridLayout->addWidget(StopBitLab, 4, 0, 1, 1);

        DataBitLab = new QLabel(ProtConfigure);
        DataBitLab->setObjectName(QString::fromUtf8("DataBitLab"));

        gridLayout->addWidget(DataBitLab, 2, 0, 1, 1);

        PortLab = new QLabel(ProtConfigure);
        PortLab->setObjectName(QString::fromUtf8("PortLab"));

        gridLayout->addWidget(PortLab, 0, 0, 1, 1);

        CleanStatsPbtn = new QPushButton(ProtConfigure);
        CleanStatsPbtn->setObjectName(QString::fromUtf8("CleanStatsPbtn"));

        gridLayout->addWidget(CleanStatsPbtn, 6, 0, 1, 2);


        gridLayout_4->addWidget(ProtConfigure, 1, 0, 1, 1);

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

        AutoFollowCbox = new QCheckBox(ReceiveGbox);
        AutoFollowCbox->setObjectName(QString::fromUtf8("AutoFollowCbox"));

        gridLayout_2->addWidget(AutoFollowCbox, 1, 1, 1, 1);

        TalkWindowCbox = new QCheckBox(ReceiveGbox);
        TalkWindowCbox->setObjectName(QString::fromUtf8("TalkWindowCbox"));

        gridLayout_2->addWidget(TalkWindowCbox, 1, 2, 1, 1);

        CleanReceivePbtn = new QPushButton(ReceiveGbox);
        CleanReceivePbtn->setObjectName(QString::fromUtf8("CleanReceivePbtn"));

        gridLayout_2->addWidget(CleanReceivePbtn, 1, 3, 1, 1);

        ReceiveTextEdit = new QTextEdit(ReceiveGbox);
        ReceiveTextEdit->setObjectName(QString::fromUtf8("ReceiveTextEdit"));
        ReceiveTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        ReceiveTextEdit->setReadOnly(true);
        ReceiveTextEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(ReceiveTextEdit, 0, 0, 1, 4);


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
        TimeSBox->setValue(100);

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
        ChartWidget = new QCustomPlot(Tab3);
        ChartWidget->setObjectName(QString::fromUtf8("ChartWidget"));

        gridLayout_7->addWidget(ChartWidget, 1, 1, 1, 1);

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
        ChartConfigure->setMinimumSize(QSize(0, 140));
        ChartConfigure->setMaximumSize(QSize(16777215, 140));
        gridLayout_6 = new QGridLayout(ChartConfigure);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        AdaptiveCbox = new QCheckBox(ChartConfigure);
        AdaptiveCbox->setObjectName(QString::fromUtf8("AdaptiveCbox"));
        AdaptiveCbox->setChecked(false);

        gridLayout_6->addWidget(AdaptiveCbox, 0, 0, 1, 1);

        ChartAutoFollowCbox = new QCheckBox(ChartConfigure);
        ChartAutoFollowCbox->setObjectName(QString::fromUtf8("ChartAutoFollowCbox"));
        ChartAutoFollowCbox->setChecked(false);

        gridLayout_6->addWidget(ChartAutoFollowCbox, 0, 1, 1, 1);

        XaxisZoomPbtn = new QPushButton(ChartConfigure);
        XaxisZoomPbtn->setObjectName(QString::fromUtf8("XaxisZoomPbtn"));

        gridLayout_6->addWidget(XaxisZoomPbtn, 0, 2, 1, 1);

        XaxisShrinkPbtn = new QPushButton(ChartConfigure);
        XaxisShrinkPbtn->setObjectName(QString::fromUtf8("XaxisShrinkPbtn"));

        gridLayout_6->addWidget(XaxisShrinkPbtn, 0, 3, 1, 1);


        gridLayout_7->addWidget(ChartConfigure, 0, 1, 1, 1);

        TabWidget->addTab(Tab3, QString());

        gridLayout_4->addWidget(TabWidget, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RLCOM", nullptr));
        LogoLab->setText(QString());
        ProtConfigure->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        CheckBitCbox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\240\241\351\252\214", nullptr));
        CheckBitCbox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));
        CheckBitCbox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));

        BaudLab->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        SwitchPortPbtn->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        StopBitCbox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBitCbox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        StopBitCbox->setItemText(2, QCoreApplication::translate("MainWindow", "1.5", nullptr));

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

        StopBitLab->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        DataBitLab->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        PortLab->setText(QCoreApplication::translate("MainWindow", "\347\253\257  \345\217\243\357\274\232", nullptr));
        CleanStatsPbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\273\237\350\256\241", nullptr));
        ReceiveGbox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        HexShowCbox->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        AutoFollowCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\267\237\350\270\252", nullptr));
        TalkWindowCbox->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235\345\274\217\347\252\227\345\217\243", nullptr));
        CleanReceivePbtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
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
        AdaptiveCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\351\200\202\345\272\224\347\252\227\345\217\243", nullptr));
        ChartAutoFollowCbox->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\267\237\350\270\252", nullptr));
        XaxisZoomPbtn->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\346\224\276\345\244\247", nullptr));
        XaxisShrinkPbtn->setText(QCoreApplication::translate("MainWindow", "X\350\275\264\347\274\251\345\260\217", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Tab3), QCoreApplication::translate("MainWindow", "\350\231\232\346\213\237\347\244\272\346\263\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

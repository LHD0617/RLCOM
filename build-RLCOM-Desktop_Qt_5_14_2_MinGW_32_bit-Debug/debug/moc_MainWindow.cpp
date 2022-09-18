/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../01.RLCOM/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UnitChartLabel_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitChartLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitChartLabel_t qt_meta_stringdata_UnitChartLabel = {
    {
QT_MOC_LITERAL(0, 0, 14) // "UnitChartLabel"

    },
    "UnitChartLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitChartLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void UnitChartLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject UnitChartLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UnitChartLabel.data,
    qt_meta_data_UnitChartLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UnitChartLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitChartLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitChartLabel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UnitChartLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "RefreshPort"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "SwitchPort"
QT_MOC_LITERAL(4, 35, 16), // "CleanReceiveData"
QT_MOC_LITERAL(5, 52, 10), // "CleanStats"
QT_MOC_LITERAL(6, 63, 13), // "CleanSendData"
QT_MOC_LITERAL(7, 77, 11), // "SwitchImage"
QT_MOC_LITERAL(8, 89, 11), // "SwitchChart"
QT_MOC_LITERAL(9, 101, 11), // "ReceiveData"
QT_MOC_LITERAL(10, 113, 8), // "SendData"
QT_MOC_LITERAL(11, 122, 8), // "AutoSend"
QT_MOC_LITERAL(12, 131, 5), // "state"
QT_MOC_LITERAL(13, 137, 14), // "WriteConfigure"
QT_MOC_LITERAL(14, 152, 13), // "ReadConfigure"
QT_MOC_LITERAL(15, 166, 9), // "MakeImage"
QT_MOC_LITERAL(16, 176, 11), // "XAxisShrink"
QT_MOC_LITERAL(17, 188, 9), // "XAxisZoom"
QT_MOC_LITERAL(18, 198, 11), // "eventFilter"
QT_MOC_LITERAL(19, 210, 3), // "obj"
QT_MOC_LITERAL(20, 214, 7), // "QEvent*"
QT_MOC_LITERAL(21, 222, 5), // "event"
QT_MOC_LITERAL(22, 228, 10), // "UpdateTime"
QT_MOC_LITERAL(23, 239, 11), // "ShowMessage"
QT_MOC_LITERAL(24, 251, 7) // "Message"

    },
    "MainWindow\0RefreshPort\0\0SwitchPort\0"
    "CleanReceiveData\0CleanStats\0CleanSendData\0"
    "SwitchImage\0SwitchChart\0ReceiveData\0"
    "SendData\0AutoSend\0state\0WriteConfigure\0"
    "ReadConfigure\0MakeImage\0XAxisShrink\0"
    "XAxisZoom\0eventFilter\0obj\0QEvent*\0"
    "event\0UpdateTime\0ShowMessage\0Message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    1,  113,    2, 0x0a /* Public */,
      13,    0,  116,    2, 0x0a /* Public */,
      14,    0,  117,    2, 0x0a /* Public */,
      15,    0,  118,    2, 0x0a /* Public */,
      16,    0,  119,    2, 0x0a /* Public */,
      17,    0,  120,    2, 0x0a /* Public */,
      18,    2,  121,    2, 0x0a /* Public */,
      22,    0,  126,    2, 0x0a /* Public */,
      23,    1,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 20,   19,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RefreshPort(); break;
        case 1: _t->SwitchPort(); break;
        case 2: _t->CleanReceiveData(); break;
        case 3: _t->CleanStats(); break;
        case 4: _t->CleanSendData(); break;
        case 5: _t->SwitchImage(); break;
        case 6: _t->SwitchChart(); break;
        case 7: _t->ReceiveData(); break;
        case 8: _t->SendData(); break;
        case 9: _t->AutoSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->WriteConfigure(); break;
        case 11: _t->ReadConfigure(); break;
        case 12: { QImage _r = _t->MakeImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->XAxisShrink(); break;
        case 14: _t->XAxisZoom(); break;
        case 15: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->UpdateTime(); break;
        case 17: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

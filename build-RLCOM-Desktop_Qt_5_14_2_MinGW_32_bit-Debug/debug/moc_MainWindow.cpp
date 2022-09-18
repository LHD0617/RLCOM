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
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[225];
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
QT_MOC_LITERAL(8, 89, 11), // "ReceiveData"
QT_MOC_LITERAL(9, 101, 8), // "SendData"
QT_MOC_LITERAL(10, 110, 8), // "AutoSend"
QT_MOC_LITERAL(11, 119, 5), // "state"
QT_MOC_LITERAL(12, 125, 14), // "WriteConfigure"
QT_MOC_LITERAL(13, 140, 13), // "ReadConfigure"
QT_MOC_LITERAL(14, 154, 9), // "MakeImage"
QT_MOC_LITERAL(15, 164, 11), // "eventFilter"
QT_MOC_LITERAL(16, 176, 3), // "obj"
QT_MOC_LITERAL(17, 180, 7), // "QEvent*"
QT_MOC_LITERAL(18, 188, 5), // "event"
QT_MOC_LITERAL(19, 194, 10), // "UpdateTime"
QT_MOC_LITERAL(20, 205, 11), // "ShowMessage"
QT_MOC_LITERAL(21, 217, 7) // "Message"

    },
    "MainWindow\0RefreshPort\0\0SwitchPort\0"
    "CleanReceiveData\0CleanStats\0CleanSendData\0"
    "SwitchImage\0ReceiveData\0SendData\0"
    "AutoSend\0state\0WriteConfigure\0"
    "ReadConfigure\0MakeImage\0eventFilter\0"
    "obj\0QEvent*\0event\0UpdateTime\0ShowMessage\0"
    "Message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    1,   97,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    2,  103,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,

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
        case 6: _t->ReceiveData(); break;
        case 7: _t->SendData(); break;
        case 8: _t->AutoSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->WriteConfigure(); break;
        case 10: _t->ReadConfigure(); break;
        case 11: { QImage _r = _t->MakeImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->UpdateTime(); break;
        case 14: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

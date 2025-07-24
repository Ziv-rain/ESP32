/****************************************************************************
** Meta object code from reading C++ file 'connectionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../connectionwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSconnectionWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSconnectionWindowENDCLASS = QtMocHelpers::stringData(
    "connectionWindow",
    "newMessageReceived",
    "",
    "topic",
    "message",
    "publishControlCommand",
    "connectButton_clicked",
    "disconnectButton_clicked",
    "updateConnectionState",
    "handleError",
    "QMqttClient::ClientError",
    "error",
    "clearSubscriptions",
    "subscribeButton_clicked",
    "handleMessageReceived",
    "QMqttMessage",
    "msg",
    "showContextMenu",
    "pos"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSconnectionWindowENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[17];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[8];
    char stringdata5[22];
    char stringdata6[22];
    char stringdata7[25];
    char stringdata8[22];
    char stringdata9[12];
    char stringdata10[25];
    char stringdata11[6];
    char stringdata12[19];
    char stringdata13[24];
    char stringdata14[22];
    char stringdata15[13];
    char stringdata16[4];
    char stringdata17[16];
    char stringdata18[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSconnectionWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSconnectionWindowENDCLASS_t qt_meta_stringdata_CLASSconnectionWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "connectionWindow"
        QT_MOC_LITERAL(17, 18),  // "newMessageReceived"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "topic"
        QT_MOC_LITERAL(43, 7),  // "message"
        QT_MOC_LITERAL(51, 21),  // "publishControlCommand"
        QT_MOC_LITERAL(73, 21),  // "connectButton_clicked"
        QT_MOC_LITERAL(95, 24),  // "disconnectButton_clicked"
        QT_MOC_LITERAL(120, 21),  // "updateConnectionState"
        QT_MOC_LITERAL(142, 11),  // "handleError"
        QT_MOC_LITERAL(154, 24),  // "QMqttClient::ClientError"
        QT_MOC_LITERAL(179, 5),  // "error"
        QT_MOC_LITERAL(185, 18),  // "clearSubscriptions"
        QT_MOC_LITERAL(204, 23),  // "subscribeButton_clicked"
        QT_MOC_LITERAL(228, 21),  // "handleMessageReceived"
        QT_MOC_LITERAL(250, 12),  // "QMqttMessage"
        QT_MOC_LITERAL(263, 3),  // "msg"
        QT_MOC_LITERAL(267, 15),  // "showContextMenu"
        QT_MOC_LITERAL(283, 3)   // "pos"
    },
    "connectionWindow",
    "newMessageReceived",
    "",
    "topic",
    "message",
    "publishControlCommand",
    "connectButton_clicked",
    "disconnectButton_clicked",
    "updateConnectionState",
    "handleError",
    "QMqttClient::ClientError",
    "error",
    "clearSubscriptions",
    "subscribeButton_clicked",
    "handleMessageReceived",
    "QMqttMessage",
    "msg",
    "showContextMenu",
    "pos"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSconnectionWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,   79,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x08,    7 /* Private */,
       7,    0,   85,    2, 0x08,    8 /* Private */,
       8,    0,   86,    2, 0x08,    9 /* Private */,
       9,    1,   87,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   12 /* Private */,
      13,    0,   91,    2, 0x08,   13 /* Private */,
      14,    2,   92,    2, 0x08,   14 /* Private */,
      17,    1,   97,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,    3,   16,
    QMetaType::Void, QMetaType::QPoint,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject connectionWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSconnectionWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSconnectionWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSconnectionWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<connectionWindow, std::true_type>,
        // method 'newMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'publishControlCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateConnectionState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMqttClient::ClientError, std::false_type>,
        // method 'clearSubscriptions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subscribeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMqttMessage &, std::false_type>,
        // method 'showContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>
    >,
    nullptr
} };

void connectionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<connectionWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->publishControlCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->connectButton_clicked(); break;
        case 3: _t->disconnectButton_clicked(); break;
        case 4: _t->updateConnectionState(); break;
        case 5: _t->handleError((*reinterpret_cast< std::add_pointer_t<QMqttClient::ClientError>>(_a[1]))); break;
        case 6: _t->clearSubscriptions(); break;
        case 7: _t->subscribeButton_clicked(); break;
        case 8: _t->handleMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMqttMessage>>(_a[2]))); break;
        case 9: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMqttClient::ClientError >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMqttMessage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (connectionWindow::*)(const QString & , const QString & );
            if (_t _q_method = &connectionWindow::newMessageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *connectionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *connectionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSconnectionWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int connectionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void connectionWindow::newMessageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

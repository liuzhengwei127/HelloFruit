/****************************************************************************
** Meta object code from reading C++ file 'aiwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clear/aiwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aiwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AIwindow_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AIwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AIwindow_t qt_meta_stringdata_AIwindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AIwindow"
QT_MOC_LITERAL(1, 9, 9), // "settxt_ai"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "userscore"
QT_MOC_LITERAL(4, 30, 7), // "aiscore"
QT_MOC_LITERAL(5, 38, 13), // "remainingline"
QT_MOC_LITERAL(6, 52, 9), // "aioperate"
QT_MOC_LITERAL(7, 62, 6), // "action"
QT_MOC_LITERAL(8, 69, 10) // "postresult"

    },
    "AIwindow\0settxt_ai\0\0userscore\0aiscore\0"
    "remainingline\0aioperate\0action\0"
    "postresult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AIwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,
       7,    0,   42,    2, 0x08 /* Private */,
       8,    3,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int,    2,    2,    2,

       0        // eod
};

void AIwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AIwindow *_t = static_cast<AIwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->settxt_ai((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->aioperate(); break;
        case 2: _t->action(); break;
        case 3: _t->postresult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AIwindow::staticMetaObject = {
    { &Gamewindow::staticMetaObject, qt_meta_stringdata_AIwindow.data,
      qt_meta_data_AIwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AIwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AIwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AIwindow.stringdata0))
        return static_cast<void*>(this);
    return Gamewindow::qt_metacast(_clname);
}

int AIwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Gamewindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'replaywindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clear/replaywindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replaywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Replaywindow_t {
    QByteArrayData data[11];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Replaywindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Replaywindow_t qt_meta_stringdata_Replaywindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Replaywindow"
QT_MOC_LITERAL(1, 13, 9), // "mousemove"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "mouserelease"
QT_MOC_LITERAL(4, 37, 10), // "timerstart"
QT_MOC_LITERAL(5, 48, 10), // "postresult"
QT_MOC_LITERAL(6, 59, 6), // "ifpass"
QT_MOC_LITERAL(7, 66, 6), // "scores"
QT_MOC_LITERAL(8, 73, 10), // "nextaction"
QT_MOC_LITERAL(9, 84, 12), // "skillrepaint"
QT_MOC_LITERAL(10, 97, 13) // "skillincscore"

    },
    "Replaywindow\0mousemove\0\0mouserelease\0"
    "timerstart\0postresult\0ifpass\0scores\0"
    "nextaction\0skillrepaint\0skillincscore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Replaywindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    2,   52,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Replaywindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Replaywindow *_t = static_cast<Replaywindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousemove(); break;
        case 1: _t->mouserelease(); break;
        case 2: _t->timerstart(); break;
        case 3: _t->postresult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->nextaction(); break;
        case 5: _t->skillrepaint(); break;
        case 6: _t->skillincscore(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Replaywindow::staticMetaObject = {
    { &Levelwindow::staticMetaObject, qt_meta_stringdata_Replaywindow.data,
      qt_meta_data_Replaywindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Replaywindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Replaywindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Replaywindow.stringdata0))
        return static_cast<void*>(this);
    return Levelwindow::qt_metacast(_clname);
}

int Replaywindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Levelwindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

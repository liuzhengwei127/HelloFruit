/****************************************************************************
** Meta object code from reading C++ file 'rankwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clear/rankwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rankwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rankwindow_t {
    QByteArrayData data[5];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rankwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rankwindow_t qt_meta_stringdata_Rankwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Rankwindow"
QT_MOC_LITERAL(1, 11, 6), // "upload"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "username"
QT_MOC_LITERAL(4, 28, 11) // "getusername"

    },
    "Rankwindow\0upload\0\0username\0getusername"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rankwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void Rankwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rankwindow *_t = static_cast<Rankwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->upload((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getusername(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Rankwindow::staticMetaObject = {
    { &Window::staticMetaObject, qt_meta_stringdata_Rankwindow.data,
      qt_meta_data_Rankwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Rankwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rankwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rankwindow.stringdata0))
        return static_cast<void*>(this);
    return Window::qt_metacast(_clname);
}

int Rankwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Window::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

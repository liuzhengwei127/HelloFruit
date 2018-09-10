/****************************************************************************
** Meta object code from reading C++ file 'levelwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clear/levelwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'levelwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Levelwindow_t {
    QByteArrayData data[19];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Levelwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Levelwindow_t qt_meta_stringdata_Levelwindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Levelwindow"
QT_MOC_LITERAL(1, 12, 15), // "signal_tryagain"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "Gamewindow*"
QT_MOC_LITERAL(4, 41, 1), // "d"
QT_MOC_LITERAL(5, 43, 16), // "signal_nextlevel"
QT_MOC_LITERAL(6, 60, 5), // "level"
QT_MOC_LITERAL(7, 66, 9), // "skillused"
QT_MOC_LITERAL(8, 76, 6), // "settxt"
QT_MOC_LITERAL(9, 83, 5), // "score"
QT_MOC_LITERAL(10, 89, 6), // "target"
QT_MOC_LITERAL(11, 96, 13), // "remainingline"
QT_MOC_LITERAL(12, 110, 10), // "postresult"
QT_MOC_LITERAL(13, 121, 6), // "ifpass"
QT_MOC_LITERAL(14, 128, 6), // "scores"
QT_MOC_LITERAL(15, 135, 8), // "tryagain"
QT_MOC_LITERAL(16, 144, 9), // "nextlevel"
QT_MOC_LITERAL(17, 154, 4), // "save"
QT_MOC_LITERAL(18, 159, 10) // "skillclose"

    },
    "Levelwindow\0signal_tryagain\0\0Gamewindow*\0"
    "d\0signal_nextlevel\0level\0skillused\0"
    "settxt\0score\0target\0remainingline\0"
    "postresult\0ifpass\0scores\0tryagain\0"
    "nextlevel\0save\0skillclose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Levelwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    2,   62,    2, 0x06 /* Public */,
       7,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   68,    2, 0x08 /* Private */,
      12,    2,   75,    2, 0x08 /* Private */,
      15,    0,   80,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,
      17,    0,   82,    2, 0x08 /* Private */,
      18,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Levelwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Levelwindow *_t = static_cast<Levelwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_tryagain((*reinterpret_cast< Gamewindow*(*)>(_a[1]))); break;
        case 1: _t->signal_nextlevel((*reinterpret_cast< Gamewindow*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->skillused(); break;
        case 3: _t->settxt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->postresult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->tryagain(); break;
        case 6: _t->nextlevel(); break;
        case 7: _t->save(); break;
        case 8: _t->skillclose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Gamewindow* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Gamewindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Levelwindow::*)(Gamewindow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Levelwindow::signal_tryagain)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Levelwindow::*)(Gamewindow * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Levelwindow::signal_nextlevel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Levelwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Levelwindow::skillused)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Levelwindow::staticMetaObject = {
    { &Gamewindow::staticMetaObject, qt_meta_stringdata_Levelwindow.data,
      qt_meta_data_Levelwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Levelwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Levelwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Levelwindow.stringdata0))
        return static_cast<void*>(this);
    return Gamewindow::qt_metacast(_clname);
}

int Levelwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Gamewindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Levelwindow::signal_tryagain(Gamewindow * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Levelwindow::signal_nextlevel(Gamewindow * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Levelwindow::skillused()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

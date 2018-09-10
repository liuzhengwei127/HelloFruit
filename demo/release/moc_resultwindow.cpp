/****************************************************************************
** Meta object code from reading C++ file 'resultwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clear/resultwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Resultwindow_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Resultwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Resultwindow_t qt_meta_stringdata_Resultwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Resultwindow"
QT_MOC_LITERAL(1, 13, 19), // "signal_returntomain"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "signal_tryagain"
QT_MOC_LITERAL(4, 50, 6), // "replay"
QT_MOC_LITERAL(5, 57, 7) // "inquire"

    },
    "Resultwindow\0signal_returntomain\0\0"
    "signal_tryagain\0replay\0inquire"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Resultwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Resultwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Resultwindow *_t = static_cast<Resultwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_returntomain(); break;
        case 1: _t->signal_tryagain(); break;
        case 2: _t->replay(); break;
        case 3: _t->inquire(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Resultwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Resultwindow::signal_returntomain)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Resultwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Resultwindow::signal_tryagain)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Resultwindow::staticMetaObject = {
    { &Window::staticMetaObject, qt_meta_stringdata_Resultwindow.data,
      qt_meta_data_Resultwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Resultwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Resultwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Resultwindow.stringdata0))
        return static_cast<void*>(this);
    return Window::qt_metacast(_clname);
}

int Resultwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Window::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Resultwindow::signal_returntomain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Resultwindow::signal_tryagain()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

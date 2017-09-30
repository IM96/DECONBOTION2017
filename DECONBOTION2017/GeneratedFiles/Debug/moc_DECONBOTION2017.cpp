/****************************************************************************
** Meta object code from reading C++ file 'DECONBOTION2017.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DECONBOTION2017.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DECONBOTION2017.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DECONBOTION2017_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DECONBOTION2017_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DECONBOTION2017_t qt_meta_stringdata_DECONBOTION2017 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DECONBOTION2017"
QT_MOC_LITERAL(1, 16, 8), // "finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "statusCam"
QT_MOC_LITERAL(4, 36, 8), // "startCam"
QT_MOC_LITERAL(5, 45, 7), // "stopCam"
QT_MOC_LITERAL(6, 53, 15) // "changeSliderval"

    },
    "DECONBOTION2017\0finished\0\0statusCam\0"
    "startCam\0stopCam\0changeSliderval"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DECONBOTION2017[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DECONBOTION2017::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DECONBOTION2017 *_t = static_cast<DECONBOTION2017 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->statusCam((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->startCam(); break;
        case 3: _t->stopCam(); break;
        case 4: _t->changeSliderval(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DECONBOTION2017::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DECONBOTION2017::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DECONBOTION2017::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DECONBOTION2017::statusCam)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DECONBOTION2017::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DECONBOTION2017.data,
      qt_meta_data_DECONBOTION2017,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DECONBOTION2017::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DECONBOTION2017::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DECONBOTION2017.stringdata0))
        return static_cast<void*>(const_cast< DECONBOTION2017*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DECONBOTION2017::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DECONBOTION2017::finished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DECONBOTION2017::statusCam(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

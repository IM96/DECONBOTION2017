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
    QByteArrayData data[15];
    char stringdata0[150];
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
QT_MOC_LITERAL(4, 36, 7), // "sendHSV"
QT_MOC_LITERAL(5, 44, 9), // "updateHSV"
QT_MOC_LITERAL(6, 54, 8), // "startCam"
QT_MOC_LITERAL(7, 63, 7), // "stopCam"
QT_MOC_LITERAL(8, 71, 15), // "changeSliderval"
QT_MOC_LITERAL(9, 87, 11), // "updateLabel"
QT_MOC_LITERAL(10, 99, 7), // "on_save"
QT_MOC_LITERAL(11, 107, 10), // "on_save_as"
QT_MOC_LITERAL(12, 118, 7), // "on_load"
QT_MOC_LITERAL(13, 126, 7), // "loadHSV"
QT_MOC_LITERAL(14, 134, 15) // "changeViewWarna"

    },
    "DECONBOTION2017\0finished\0\0statusCam\0"
    "sendHSV\0updateHSV\0startCam\0stopCam\0"
    "changeSliderval\0updateLabel\0on_save\0"
    "on_save_as\0on_load\0loadHSV\0changeViewWarna"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DECONBOTION2017[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    9,   85,    2, 0x06 /* Public */,
       5,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  105,    2, 0x0a /* Public */,
       7,    0,  106,    2, 0x0a /* Public */,
       8,    0,  107,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    0,  110,    2, 0x0a /* Public */,
      12,    0,  111,    2, 0x0a /* Public */,
      13,    0,  112,    2, 0x0a /* Public */,
      14,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,

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
        case 2: _t->sendHSV((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 3: _t->updateHSV(); break;
        case 4: _t->startCam(); break;
        case 5: _t->stopCam(); break;
        case 6: _t->changeSliderval(); break;
        case 7: _t->updateLabel(); break;
        case 8: _t->on_save(); break;
        case 9: _t->on_save_as(); break;
        case 10: _t->on_load(); break;
        case 11: _t->loadHSV(); break;
        case 12: _t->changeViewWarna(); break;
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
        {
            typedef void (DECONBOTION2017::*_t)(int , int , int , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DECONBOTION2017::sendHSV)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DECONBOTION2017::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DECONBOTION2017::updateHSV)) {
                *result = 3;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
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

// SIGNAL 2
void DECONBOTION2017::sendHSV(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, int _t8, int _t9)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DECONBOTION2017::updateHSV()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'AbstractShape.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AbstractShape.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AbstractShape.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AbstractShape_t {
    QByteArrayData data[6];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractShape_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractShape_t qt_meta_stringdata_AbstractShape = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AbstractShape"
QT_MOC_LITERAL(1, 14, 6), // "setPen"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "pen"
QT_MOC_LITERAL(4, 26, 8), // "setBrush"
QT_MOC_LITERAL(5, 35, 5) // "brush"

    },
    "AbstractShape\0setPen\0\0pen\0setBrush\0"
    "brush"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractShape[] = {

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
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPen,    3,
    QMetaType::Void, QMetaType::QBrush,    5,

       0        // eod
};

void AbstractShape::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractShape *_t = static_cast<AbstractShape *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 1: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AbstractShape::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractShape.data,
      qt_meta_data_AbstractShape,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AbstractShape::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractShape::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractShape.stringdata0))
        return static_cast<void*>(const_cast< AbstractShape*>(this));
    return QWidget::qt_metacast(_clname);
}

int AbstractShape::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

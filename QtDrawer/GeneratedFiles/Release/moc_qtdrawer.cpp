/****************************************************************************
** Meta object code from reading C++ file 'qtdrawer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtdrawer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtdrawer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtDrawer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x08,
      52,   10,    9,    9, 0x08,
      87,    9,    9,    9, 0x08,
      98,    9,    9,    9, 0x08,
     109,    9,    9,    9, 0x08,
     127,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtDrawer[] = {
    "QtDrawer\0\0item\0slotDoubleUnSigned(QListWidgetItem*)\0"
    "slotDoubleSigned(QListWidgetItem*)\0"
    "slotSave()\0slotExit()\0slotColorSelect()\0"
    "slotReDraw()\0"
};

void QtDrawer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtDrawer *_t = static_cast<QtDrawer *>(_o);
        switch (_id) {
        case 0: _t->slotDoubleUnSigned((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slotDoubleSigned((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slotSave(); break;
        case 3: _t->slotExit(); break;
        case 4: _t->slotColorSelect(); break;
        case 5: _t->slotReDraw(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtDrawer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtDrawer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtDrawer,
      qt_meta_data_QtDrawer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtDrawer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtDrawer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtDrawer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtDrawer))
        return static_cast<void*>(const_cast< QtDrawer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtDrawer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

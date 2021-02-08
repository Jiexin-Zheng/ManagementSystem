/****************************************************************************
** Meta object code from reading C++ file 'equipmentshowdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Information_control_system/dialog/equipmentshowdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'equipmentshowdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EquipmentShowDialog_t {
    QByteArrayData data[9];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EquipmentShowDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EquipmentShowDialog_t qt_meta_stringdata_EquipmentShowDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "EquipmentShowDialog"
QT_MOC_LITERAL(1, 20, 30), // "on_sortByMatchIdButton_clicked"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 27), // "on_sortByNameButton_clicked"
QT_MOC_LITERAL(4, 80, 27), // "on_sortByAreaButton_clicked"
QT_MOC_LITERAL(5, 108, 21), // "on_editButton_clicked"
QT_MOC_LITERAL(6, 130, 21), // "on_nameButton_clicked"
QT_MOC_LITERAL(7, 152, 24), // "on_matchIdButton_clicked"
QT_MOC_LITERAL(8, 177, 21) // "on_areaButton_clicked"

    },
    "EquipmentShowDialog\0on_sortByMatchIdButton_clicked\0"
    "\0on_sortByNameButton_clicked\0"
    "on_sortByAreaButton_clicked\0"
    "on_editButton_clicked\0on_nameButton_clicked\0"
    "on_matchIdButton_clicked\0on_areaButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EquipmentShowDialog[] = {

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
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EquipmentShowDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EquipmentShowDialog *_t = static_cast<EquipmentShowDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sortByMatchIdButton_clicked(); break;
        case 1: _t->on_sortByNameButton_clicked(); break;
        case 2: _t->on_sortByAreaButton_clicked(); break;
        case 3: _t->on_editButton_clicked(); break;
        case 4: _t->on_nameButton_clicked(); break;
        case 5: _t->on_matchIdButton_clicked(); break;
        case 6: _t->on_areaButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EquipmentShowDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EquipmentShowDialog.data,
      qt_meta_data_EquipmentShowDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EquipmentShowDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EquipmentShowDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EquipmentShowDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EquipmentShowDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

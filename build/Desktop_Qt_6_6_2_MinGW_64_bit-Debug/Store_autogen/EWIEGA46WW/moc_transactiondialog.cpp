/****************************************************************************
** Meta object code from reading C++ file 'transactiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../transactiondialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transactiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTransactionDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTransactionDialogENDCLASS = QtMocHelpers::stringData(
    "TransactionDialog",
    "transactionCompleted",
    "",
    "onAddItem",
    "onDone",
    "openNewCustomerDialog",
    "handleCustomerAdded",
    "name"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTransactionDialogENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[18];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[7];
    char stringdata5[22];
    char stringdata6[20];
    char stringdata7[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTransactionDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTransactionDialogENDCLASS_t qt_meta_stringdata_CLASSTransactionDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "TransactionDialog"
        QT_MOC_LITERAL(18, 20),  // "transactionCompleted"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 9),  // "onAddItem"
        QT_MOC_LITERAL(50, 6),  // "onDone"
        QT_MOC_LITERAL(57, 21),  // "openNewCustomerDialog"
        QT_MOC_LITERAL(79, 19),  // "handleCustomerAdded"
        QT_MOC_LITERAL(99, 4)   // "name"
    },
    "TransactionDialog",
    "transactionCompleted",
    "",
    "onAddItem",
    "onDone",
    "openNewCustomerDialog",
    "handleCustomerAdded",
    "name"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTransactionDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    1,   48,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject TransactionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTransactionDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTransactionDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTransactionDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TransactionDialog, std::true_type>,
        // method 'transactionCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openNewCustomerDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCustomerAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void TransactionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TransactionDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->transactionCompleted(); break;
        case 1: _t->onAddItem(); break;
        case 2: _t->onDone(); break;
        case 3: _t->openNewCustomerDialog(); break;
        case 4: _t->handleCustomerAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TransactionDialog::*)();
            if (_t _q_method = &TransactionDialog::transactionCompleted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *TransactionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransactionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTransactionDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TransactionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TransactionDialog::transactionCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP

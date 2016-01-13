/********************************************************************************
** Form generated from reading UI file 'qtdrawer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDRAWER_H
#define UI_QTDRAWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDrawerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetUnSign;
    QWidget *widget;
    QListWidget *listWidgetSigned;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButtonColor;
    QPushButton *pushButtonReDraw;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonExit;

    void setupUi(QMainWindow *QtDrawerClass)
    {
        if (QtDrawerClass->objectName().isEmpty())
            QtDrawerClass->setObjectName(QString::fromUtf8("QtDrawerClass"));
        QtDrawerClass->resize(800, 627);
        centralWidget = new QWidget(QtDrawerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidgetUnSign = new QListWidget(centralWidget);
        listWidgetUnSign->setObjectName(QString::fromUtf8("listWidgetUnSign"));
        listWidgetUnSign->setMinimumSize(QSize(120, 0));
        listWidgetUnSign->setMaximumSize(QSize(120, 16777215));
        listWidgetUnSign->setStyleSheet(QString::fromUtf8("QListWidget::item{height:35px;}\n"
""));
        listWidgetUnSign->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(listWidgetUnSign);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(widget);

        listWidgetSigned = new QListWidget(centralWidget);
        listWidgetSigned->setObjectName(QString::fromUtf8("listWidgetSigned"));
        listWidgetSigned->setMinimumSize(QSize(120, 0));
        listWidgetSigned->setMaximumSize(QSize(120, 16777215));
        listWidgetSigned->setStyleSheet(QString::fromUtf8("QListWidget::item{height:35px;}\n"
""));

        horizontalLayout->addWidget(listWidgetSigned);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pushButtonColor = new QPushButton(centralWidget);
        pushButtonColor->setObjectName(QString::fromUtf8("pushButtonColor"));
        pushButtonColor->setStyleSheet(QString::fromUtf8("background-color: rgba(255,128,0,200);"));

        horizontalLayout_2->addWidget(pushButtonColor);

        pushButtonReDraw = new QPushButton(centralWidget);
        pushButtonReDraw->setObjectName(QString::fromUtf8("pushButtonReDraw"));

        horizontalLayout_2->addWidget(pushButtonReDraw);

        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonExit = new QPushButton(centralWidget);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));

        horizontalLayout_2->addWidget(pushButtonExit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        QtDrawerClass->setCentralWidget(centralWidget);

        retranslateUi(QtDrawerClass);

        QMetaObject::connectSlotsByName(QtDrawerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDrawerClass)
    {
        QtDrawerClass->setWindowTitle(QApplication::translate("QtDrawerClass", "QtDrawer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QtDrawerClass", "\351\242\234 \350\211\262", 0, QApplication::UnicodeUTF8));
        pushButtonColor->setText(QString());
        pushButtonReDraw->setText(QApplication::translate("QtDrawerClass", "\351\207\215\345\206\231", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("QtDrawerClass", "\345\256\214\346\210\220", 0, QApplication::UnicodeUTF8));
        pushButtonExit->setText(QApplication::translate("QtDrawerClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtDrawerClass: public Ui_QtDrawerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDRAWER_H

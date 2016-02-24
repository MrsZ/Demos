/********************************************************************************
** Form generated from reading UI file 'qtdrawer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDRAWER_H
#define UI_QTDRAWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDrawerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QListWidget *listWidgetUnSign;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QListWidget *listWidgetSigned;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButtonColor;
    QPushButton *pushButtonReDraw;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonExit;

    void setupUi(QMainWindow *QtDrawerClass)
    {
        if (QtDrawerClass->objectName().isEmpty())
            QtDrawerClass->setObjectName(QStringLiteral("QtDrawerClass"));
        QtDrawerClass->resize(840, 500);
        centralWidget = new QWidget(QtDrawerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(160, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        listWidgetUnSign = new QListWidget(centralWidget);
        listWidgetUnSign->setObjectName(QStringLiteral("listWidgetUnSign"));
        listWidgetUnSign->setMinimumSize(QSize(160, 0));
        listWidgetUnSign->setMaximumSize(QSize(160, 16777215));
        listWidgetUnSign->setStyleSheet(QLatin1String("QListWidget::item{height:35px;}\n"
""));
        listWidgetUnSign->setIconSize(QSize(32, 32));

        verticalLayout_4->addWidget(listWidgetUnSign);


        horizontalLayout->addLayout(verticalLayout_4);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(500, 500));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(widget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(160, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        listWidgetSigned = new QListWidget(centralWidget);
        listWidgetSigned->setObjectName(QStringLiteral("listWidgetSigned"));
        listWidgetSigned->setMinimumSize(QSize(160, 0));
        listWidgetSigned->setMaximumSize(QSize(160, 16777215));
        listWidgetSigned->setStyleSheet(QLatin1String("QListWidget::item{height:35px;}\n"
""));

        verticalLayout_5->addWidget(listWidgetSigned);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 40));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        pushButtonColor = new QPushButton(centralWidget);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));
        pushButtonColor->setMinimumSize(QSize(60, 40));
        pushButtonColor->setMaximumSize(QSize(60, 16777215));
        pushButtonColor->setStyleSheet(QStringLiteral("background-color: rgba(255,128,0,200);"));

        horizontalLayout_2->addWidget(pushButtonColor);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButtonReDraw = new QPushButton(centralWidget);
        pushButtonReDraw->setObjectName(QStringLiteral("pushButtonReDraw"));
        pushButtonReDraw->setMinimumSize(QSize(160, 40));
        pushButtonReDraw->setMaximumSize(QSize(120, 16777215));
        pushButtonReDraw->setFont(font);

        verticalLayout->addWidget(pushButtonReDraw);

        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(160, 40));
        pushButtonSave->setMaximumSize(QSize(120, 16777215));
        pushButtonSave->setFont(font);

        verticalLayout->addWidget(pushButtonSave);

        pushButtonExit = new QPushButton(centralWidget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));
        pushButtonExit->setMinimumSize(QSize(160, 40));
        pushButtonExit->setMaximumSize(QSize(120, 16777215));
        pushButtonExit->setFont(font);

        verticalLayout->addWidget(pushButtonExit);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        QtDrawerClass->setCentralWidget(centralWidget);

        retranslateUi(QtDrawerClass);

        QMetaObject::connectSlotsByName(QtDrawerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDrawerClass)
    {
        QtDrawerClass->setWindowTitle(QApplication::translate("QtDrawerClass", "QtDrawer", 0));
        label_2->setText(QApplication::translate("QtDrawerClass", "\346\234\252\347\255\276\345\210\260", 0));
        label_3->setText(QApplication::translate("QtDrawerClass", "\345\267\262\347\255\276\345\210\260", 0));
        label->setText(QApplication::translate("QtDrawerClass", "\351\242\234 \350\211\262", 0));
        pushButtonColor->setText(QString());
        pushButtonReDraw->setText(QApplication::translate("QtDrawerClass", "\351\207\215\345\206\231", 0));
        pushButtonSave->setText(QApplication::translate("QtDrawerClass", "\345\256\214\346\210\220", 0));
        pushButtonExit->setText(QApplication::translate("QtDrawerClass", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class QtDrawerClass: public Ui_QtDrawerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDRAWER_H

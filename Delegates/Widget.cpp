//
// Created by kestiny on 2015/11/14.
//

#include "Widget.h"
#include <QPushButton>
#include <QMessageBox>
#include "delegatecombobox.h"
#include "delegatenumber.h"
#include "delegateicon.h"
#include "delegatespinbox.h"

Widget::Widget() {
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotPushbutton()));
	// ≤‚ ‘comboBox¥˙¿Ì
    DelegateComboBox* pComDelegate = new DelegateComboBox(
		QStringList() << "11" << "22" << "33");
    ui.tableWidget->setItemDelegateForColumn(0, pComDelegate);
    ui.tableWidget->setRowCount(5);

	// ≤‚ ‘ ˝◊÷¥˙¿Ì
	ui.tableWidget->setItemDelegateForColumn(1, new DelegateNumber(true));
	ui.tableWidget->setItemDelegateForColumn(2, new DelegateNumber(false));

	// ≤‚ ‘Icon
	ui.tableWidget->setItemDelegateForColumn(3, new DelegateIcon("D:/project/QtDemo/Win32/1111.png", 32, 32));

	// ≤‚ ‘SpinBox
	ui.tableWidget->setItemDelegateForColumn(4, new DelegateSpinBox(0, 1000));
    int i = 0;
    QTableWidgetItem* pItem = new QTableWidgetItem;
    pItem->setText("11");
    ui.tableWidget->setItem(i, 0, pItem);
    pItem = new QTableWidgetItem;
    pItem->setText("11");
    ui.tableWidget->setItem(i, 1, pItem);

    ++i;
    pItem = new QTableWidgetItem;
    pItem->setText("22");
    ui.tableWidget->setItem(i, 0, pItem);
    pItem = new QTableWidgetItem;
    pItem->setText("22");
    ui.tableWidget->setItem(i, 1, pItem);
}

Widget::~Widget() {

}

void Widget::slotPushbutton() {
    QMessageBox::information(this, "Title", "Hello CLion!");

    ui.tableWidget->item(0, 1)->setText(ui.tableWidget->item(1, 0)->text());
    ui.tableWidget->item(1, 1)->setText(ui.tableWidget->item(0, 0)->text());
}

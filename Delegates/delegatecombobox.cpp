#include "delegatecombobox.h"

DelegateComboBox::DelegateComboBox(const QStringList& items, QObject *parent)
	: m_listItems(items), QItemDelegate(parent)
{

}

DelegateComboBox::~DelegateComboBox()
{

}

QWidget* DelegateComboBox::createEditor(QWidget* parent,
										const QStyleOptionViewItem& option,
										const QModelIndex& index) const
{
	QComboBox* editor = new QComboBox(parent);
	editor->addItems(m_listItems);
	return editor;
}

void DelegateComboBox::setEditorData(QWidget* editor,
									 const QModelIndex& index) const
{
	QString text = index.model()->data(index, Qt::EditRole).toString();
	QComboBox* comboBox = static_cast<QComboBox*>(editor);
	comboBox->setCurrentIndex(comboBox->findText(text));
}

void DelegateComboBox::setModelData(QWidget* editor,
									QAbstractItemModel* model,
									const QModelIndex& index) const
{
	QComboBox* comboBox = static_cast<QComboBox*>(editor);
	QString text = comboBox->currentText();
	model->setData(index, text, Qt::EditRole);
}

void DelegateComboBox::updateEditorGeometry(QWidget* editor,
											const QStyleOptionViewItem& option,
											const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}

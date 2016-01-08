#include "delegatespinbox.h"

DelegateSpinBox::DelegateSpinBox(int min, int max, QObject *parent)
	: m_iMin(min), m_iMax(max), QItemDelegate(parent)
{

}

DelegateSpinBox::~DelegateSpinBox()
{

}

QWidget* DelegateSpinBox::createEditor(QWidget* parent,
									   const QStyleOptionViewItem& option,
									   const QModelIndex& index 
									   ) const
{
	QSpinBox* pSpinBox = new QSpinBox(parent);
	pSpinBox->setMinimum(m_iMin);
	pSpinBox->setMaximum(m_iMax);
	return pSpinBox;
}

void DelegateSpinBox::setEditorData(QWidget* editor,
									const QModelIndex& index) const
{
	int value = index.model()->data(index, Qt::EditRole).toInt();
	QSpinBox* pSpinBox = static_cast<QSpinBox*>(editor);
	pSpinBox->setValue(value);
}


void DelegateSpinBox::setModelData(QWidget* editor,
								   QAbstractItemModel* model,
								   const QModelIndex& index) const
{
	QSpinBox* pSpinBox = static_cast<QSpinBox*>(editor);
	pSpinBox->interpretText();
	model->setData(index, pSpinBox->value(), Qt::EditRole);
}

void DelegateSpinBox::updateEditorGeometry(QWidget* editor,
										   const QStyleOptionViewItem& option,
										   const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}

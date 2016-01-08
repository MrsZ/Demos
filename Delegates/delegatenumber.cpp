#include "delegatenumber.h"
#include <QRegExp>

DelegateNumber::DelegateNumber(bool isInteger/* = true*/, QObject *parent)
	: m_bIsInteger(isInteger), QItemDelegate(parent)
{

}

DelegateNumber::~DelegateNumber()
{

}

QWidget* DelegateNumber::createEditor(QWidget* parent,
									  const QStyleOptionViewItem& option,
									  const QModelIndex& index) const
{
	QLineEdit* pEdit = new QLineEdit(parent);
	QRegExp reg;
	if (m_bIsInteger)
	{
		reg = QRegExp("[0-9]{0,}");
	}
	else
	{
		reg = QRegExp("[0-9]{1,}[.]?[0-9]{0,}");
	}
	
	pEdit->setValidator(new QRegExpValidator(reg, parent));
	return pEdit;
}

void DelegateNumber::setEditorData(QWidget* editor,
								   const QModelIndex& index) const
{
	QString text = index.model()->data(index, Qt::EditRole).toString();
	QLineEdit* pEdit = static_cast<QLineEdit*>(editor);
	pEdit->setText(text);
}

void DelegateNumber::setModelData(QWidget* editor,
								  QAbstractItemModel* model,
								  const QModelIndex& index) const
{
	QLineEdit* pEidt = static_cast<QLineEdit*>(editor);
	QString text = pEidt->text();
	model->setData(index, text, Qt::EditRole);
}

void DelegateNumber::updateEditorGeometry(QWidget* editor,
										  const QStyleOptionViewItem& option,
										  const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}

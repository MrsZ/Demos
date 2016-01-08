#ifndef DELEGATECOMBOBOX_H
#define DELEGATECOMBOBOX_H

#include <QItemDelegate>
#include <QComboBox>

// 代理comboBox，可以在表格中使用
class DelegateComboBox : public QItemDelegate
{
	Q_OBJECT

public:
	DelegateComboBox(const QStringList& items, QObject *parent = 0);
	~DelegateComboBox();

protected:
	virtual QWidget* createEditor(QWidget* parent,
		const QStyleOptionViewItem& option,
		const QModelIndex& index ) const;

	 virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;

	 virtual void setModelData(QWidget* editor, QAbstractItemModel* model,
		 const QModelIndex& index) const;

	 virtual void updateEditorGeometry(QWidget* editor,
		 const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
	QStringList m_listItems;
};

#endif // DELEGATECOMBOBOX_H

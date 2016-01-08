#ifndef DELEGATESPINBOX_H
#define DELEGATESPINBOX_H

#include <QItemDelegate>
#include <QSpinBox>

class DelegateSpinBox : public QItemDelegate
{
	Q_OBJECT

public:
	DelegateSpinBox(int min = 0, int max = 99, QObject *parent = 0);
	~DelegateSpinBox();

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
	int m_iMin;
	int m_iMax;
};

#endif // DELEGATESPINBOX_H

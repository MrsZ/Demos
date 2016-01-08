#ifndef DELEGATENUMBER_H
#define DELEGATENUMBER_H

#include <QItemDelegate>
#include <QLineEdit>

// 代理数字，只能输入数字
class DelegateNumber : public QItemDelegate
{
	Q_OBJECT

public:
	DelegateNumber(bool isInteger = true, QObject* parent = 0);
	~DelegateNumber();

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
	bool m_bIsInteger;            // 是否为整数
};

#endif // DELEGATENUMBER_H

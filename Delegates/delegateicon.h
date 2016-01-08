#ifndef DELEGATEICON_H
#define DELEGATEICON_H

#include <QItemDelegate>
#include <QPixmap>
#include <QPainter>

class DelegateIcon : public QItemDelegate
{
	Q_OBJECT

public:
	DelegateIcon(const QString& strName, int x, int y, QObject *parent = 0);
	~DelegateIcon();

protected:
	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

private:
	QString m_strIconName;
	int m_iWidth;
	int m_iHeight;
};

#endif // DELEGATEICON_H

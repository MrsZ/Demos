#include "delegateicon.h"

DelegateIcon::DelegateIcon(const QString& strName, int x, int y, QObject *parent)
	: m_strIconName(strName), m_iWidth(x), m_iHeight(y), QItemDelegate(parent)
{

}

DelegateIcon::~DelegateIcon()
{

}

void DelegateIcon::paint(QPainter* painter,
						 const QStyleOptionViewItem& option,
						 const QModelIndex& index 
						 ) const
{
	QPixmap pixmap = QPixmap(m_strIconName).scaled(m_iWidth, m_iHeight);

	int width = pixmap.width();
	int height = pixmap.height();
	QRect rect = option.rect;
	int x = rect.x() + rect.width() / 2-width / 2;
	int y = rect.y() + rect.height() / 2-height / 2;

	painter->drawPixmap(x, y, pixmap);
}

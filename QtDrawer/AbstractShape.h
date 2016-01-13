#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPixmap>

class AbstractShape : public QWidget
{
	Q_OBJECT

public:
	enum Category {Curve, Line, Rect, Text};

	explicit AbstractShape(QWidget *parent = 0);

	QPoint getBeginPoint()
	{
		return beginPoint;
	}

	void setBeginPoint(QPoint point)
	{
		this->beginPoint = point;
	}

	QPoint getEndPoint()
	{
		return endPoint;
	}

	void setEndPoint(QPoint point)
	{
		this->endPoint = point;
	}

	void virtual draw(QPainter &painter) = 0; //��Ҫ����ͼ������ʵ��
	void virtual addPoint(QPoint point) = 0; //Ϊ�˻�����������������һ������

	void setPenColor(QColor color);

public slots:
	void setPen(const QPen &pen);
	void setBrush(const QBrush &brush);

protected:    
	QPoint beginPoint;
	QPoint endPoint;
	QBrush brush;
	QPen pen;
};

#endif // ABSTRACTSHAPE_H
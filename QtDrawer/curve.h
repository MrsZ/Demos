#ifndef CURVE_H
#define CURVE_H

#include "abstractshape.h"
#include <Qpainter>
#include <QVector>
#include <QPointF>
#include <QPolygon>

class Curve : public AbstractShape
{
public:
	Curve();

	QPoint getBeginPoint()
	{
		return points.at(0); //重写了父类的方法，其他图形应该使用父类的方法即可
	}

	void setBeginPoint(QPoint point)
	{
		this->addPoint(point); //重写了父类的方法，其他图形应该使用父类的方法即可
	}

	QPoint getEndPoint()
	{
		return points.at(points.size() - 1); //重写了父类的方法，其他图形应该使用父类的方法即可
	}

	void setEndPoint(QPoint point)
	{
		this->addPoint(point); //重写了父类的方法，其他图形应该使用父类的方法即可
	}

	void addPoint(QPoint point);

	void draw(QPainter &painter);

protected:

private:
	QVector<QPoint> points; //曲线其实就是一堆QPoint的点集合，此处存放，鼠标移动时候将点存入此处
};

#endif // CURVE_H
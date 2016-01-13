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
		return points.at(0); //��д�˸���ķ���������ͼ��Ӧ��ʹ�ø���ķ�������
	}

	void setBeginPoint(QPoint point)
	{
		this->addPoint(point); //��д�˸���ķ���������ͼ��Ӧ��ʹ�ø���ķ�������
	}

	QPoint getEndPoint()
	{
		return points.at(points.size() - 1); //��д�˸���ķ���������ͼ��Ӧ��ʹ�ø���ķ�������
	}

	void setEndPoint(QPoint point)
	{
		this->addPoint(point); //��д�˸���ķ���������ͼ��Ӧ��ʹ�ø���ķ�������
	}

	void addPoint(QPoint point);

	void draw(QPainter &painter);

protected:

private:
	QVector<QPoint> points; //������ʵ����һ��QPoint�ĵ㼯�ϣ��˴���ţ�����ƶ�ʱ�򽫵����˴�
};

#endif // CURVE_H
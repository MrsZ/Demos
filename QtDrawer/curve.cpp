#include "curve.h"

Curve::Curve()
{
}

void Curve::addPoint(QPoint point)
{
	this->points.append(point);
}

void Curve::draw(QPainter &painter)
{
	painter.setPen(pen);
	painter.setBrush(brush);

	//�˴��ǻ��������ߵĹؼ�������޸�ΪdrawPolygon�����Կ�����껭ͼ��ʵ���ˣ�������ʼ�ͽ��������һ��   ֱ������
	painter.drawPolyline(QPolygonF(points));
}

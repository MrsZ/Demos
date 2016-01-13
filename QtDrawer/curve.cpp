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

	//此处是画任意曲线的关键，如果修改为drawPolygon，可以看到鼠标画图是实现了，但在起始和结束点均有一条   直线相连
	painter.drawPolyline(QPolygonF(points));
}

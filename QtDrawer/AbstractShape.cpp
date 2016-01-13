#include "abstractshape.h"

AbstractShape::AbstractShape(QWidget *parent) :
QWidget(parent)
{
	this->pen.setStyle(Qt::SolidLine);
	this->pen.setWidth(10);
	this->pen.setColor(QColor(255,128,0,200));
	setBackgroundRole(QPalette::Base);
}

void AbstractShape::setPen(const QPen &pen)
{
	this->pen = pen;
	this->pen.setStyle(Qt::SolidLine);
}

void AbstractShape::setBrush(const QBrush &brush)
{
	this->brush = brush;
}

void AbstractShape::setPenColor(QColor color)
{
	this->pen.setColor(color);
}

#include "drawareawidget.h"

DrawAreaWidget::DrawAreaWidget(QWidget *parent) :
QWidget(parent)
{
	m_strPixmapPath = "./Hydrangeas.jpg";
	m_color = QColor(255,128,0,200);
	init();
}

void DrawAreaWidget::init()
{
	currentShape = NULL;
	currentCategory = AbstractShape::Curve;
	isLeftButtonPressed = false;
	shapes.clear();

 	QImage _image;
 	_image.load(m_strPixmapPath);
	setFixedSize(_image.size());
 	setAutoFillBackground(true);   // 这个属性一定要设置
 	QPalette pal(palette());
 	pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
 		Qt::SmoothTransformation)));
 	setPalette(pal);
}

void DrawAreaWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	//抗锯齿
	painter.setRenderHint(QPainter::Antialiasing, true);

	foreach(AbstractShape *shape, shapes)
	{
		shape->draw(painter);
	}
}

void DrawAreaWidget::mousePressEvent(QMouseEvent *event)
{
	switch(currentCategory)
	{
	case AbstractShape::Curve:
		{
			currentShape = new Curve;
			currentShape->setPenColor(m_color);
			break;
		}
	}

	if(currentShape != NULL)
	{
		isLeftButtonPressed = true;

		currentShape->setBeginPoint(event->pos());
		shapes.append(currentShape);
	}
}

void DrawAreaWidget::mouseReleaseEvent(QMouseEvent *event)
{
	currentShape->setEndPoint(event->pos());
	isLeftButtonPressed = false;
}

void DrawAreaWidget::mouseMoveEvent(QMouseEvent *event)
{
	if(currentShape && isLeftButtonPressed)
	{
		currentShape->addPoint(event->pos());
		update();
	}
}

void DrawAreaWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);

 	QImage _image;
 	_image.load(m_strPixmapPath);
 	QPalette pal(palette());
 	pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
 	setPalette(pal);
}

void DrawAreaWidget::setPixmapPath( const QString& name, int width, int height )
{
	m_strPixmapPath = name;

	currentShape = NULL;
	currentCategory = AbstractShape::Curve;
	isLeftButtonPressed = false;
	shapes.clear();

	QImage _image;
	_image.load(m_strPixmapPath);
	_image = _image.scaled(width, height, Qt::KeepAspectRatio);
	setFixedSize(_image.size());
	setAutoFillBackground(true);   // 这个属性一定要设置
	QPalette pal(palette());
	pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
		Qt::SmoothTransformation)));
	setPalette(pal);
}

void DrawAreaWidget::setPenColor(QColor color)
{
	m_color = color;
}

void DrawAreaWidget::clearWidget()
{
	shapes.clear();
	update();
}

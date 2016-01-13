#ifndef DRAWAREAWIDGET_H
#define DRAWAREAWIDGET_H

#include <QWidget>
#include <QPainter>

#include "abstractshape.h"
#include "curve.h"
#include <QList>
#include <QMouseEvent>
#include <QPaintEvent>

class DrawAreaWidget : public QWidget
{
	Q_OBJECT
public:
	explicit DrawAreaWidget(QWidget *parent = 0);
	void init();

	void setPixmapPath(const QString& name, int width, int height);
	void setPenColor(QColor color);
	void clearWidget();

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	QList<AbstractShape *> shapes;
	AbstractShape *currentShape;
	AbstractShape::Category currentCategory;
	bool isLeftButtonPressed;
	QString m_strPixmapPath;
	QColor m_color;
};

#endif // DRAWAREAWIDGET_H
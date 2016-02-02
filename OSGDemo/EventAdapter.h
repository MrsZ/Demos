#ifndef EVENTADAPTER_H
#define EVENTADAPTER_H
#include <QInputEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QGLWidget>
#include <osgViewer/GraphicsWindow>

class EventAdapter : public QGLWidget
{
public:
	EventAdapter(QWidget *parent = 0);
	~EventAdapter();

protected:
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent* event);
	virtual void resizeEvent(QResizeEvent *event);
	virtual void moveEvent(QMoveEvent* event);
	virtual void timerEvent(QTimerEvent *event);

protected:
	osgViewer::GraphicsWindow* m_pGraphicsWindow;

private:
	void setKeyboardModifiers(QInputEvent* event);
};

#endif // EVENTADAPTER_H

#include "EventAdapter.h"
#include <QPaintEngine>

EventAdapter::EventAdapter(QWidget *parent)
: QGLWidget(parent)
{
	
}

EventAdapter::~EventAdapter()
{

}

void EventAdapter::setKeyboardModifiers(QInputEvent* event)
{
	int modkey = event->modifiers() & (Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier);
	unsigned int mask = 0;
	if (modkey & Qt::ShiftModifier) mask |= osgGA::GUIEventAdapter::MODKEY_SHIFT;
	if (modkey & Qt::ControlModifier) mask |= osgGA::GUIEventAdapter::MODKEY_CTRL;
	if (modkey & Qt::AltModifier) mask |= osgGA::GUIEventAdapter::MODKEY_ALT;

	m_pGraphicsWindow->getEventQueue()->getCurrentEventState()->setModKeyMask(mask);
}

void EventAdapter::keyPressEvent(QKeyEvent* event)
{
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()->keyPress(
		(osgGA::GUIEventAdapter::KeySymbol)*(event->text().toLatin1().data()));
	QGLWidget::keyPressEvent(event);
}

void EventAdapter::keyReleaseEvent(QKeyEvent* event)
{
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()->keyRelease(
		(osgGA::GUIEventAdapter::KeySymbol)*(event->text().toLatin1().data()));

	QGLWidget::keyReleaseEvent(event);
}

void EventAdapter::mousePressEvent(QMouseEvent* event)
{
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton: button = 1; break;
	case Qt::MidButton: button = 2; break;
	case Qt::RightButton: button = 3; break;
	case Qt::NoButton: button = 0; break;
	default: button = 0; break;
	}
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()
		->mouseButtonPress(event->x(), event->y(), button);
}

void EventAdapter::mouseReleaseEvent(QMouseEvent* event)
{
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton: button = 1; break;
	case Qt::MidButton: button = 2; break;
	case Qt::RightButton: button = 3; break;
	case Qt::NoButton: button = 0; break;
	default: button = 0; break;
	}
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);

	QGLWidget::mouseReleaseEvent(event);
}

void EventAdapter::mouseDoubleClickEvent(QMouseEvent* event)
{
	int button = 0;
	switch (event->button())
	{
	case Qt::LeftButton: button = 1; break;
	case Qt::MidButton: button = 2; break;
	case Qt::RightButton: button = 3; break;
	case Qt::NoButton: button = 0; break;
	default: button = 0; break;
	}
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()
		->mouseDoubleButtonPress(event->x(), event->y(), button);

	QGLWidget::mouseDoubleClickEvent(event);
}

void EventAdapter::mouseMoveEvent(QMouseEvent* event)
{
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()->mouseMotion(event->x(), event->y());
	QGLWidget::mouseMoveEvent(event);
}

void EventAdapter::wheelEvent(QWheelEvent* event)
{
	setKeyboardModifiers(event);
	m_pGraphicsWindow->getEventQueue()->mouseScroll(
		event->orientation() == Qt::Vertical ?
		(event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN) :
		(event->delta() > 0 ? osgGA::GUIEventAdapter::SCROLL_LEFT : osgGA::GUIEventAdapter::SCROLL_RIGHT));
	QGLWidget::wheelEvent(event);
}

void EventAdapter::resizeEvent(QResizeEvent *event)
{
	const QSize& size = event->size();
	m_pGraphicsWindow->resized(x(), y(), size.width(), size.height());
	m_pGraphicsWindow->getEventQueue()->windowResize(x(), y(), size.width(), size.height());
	m_pGraphicsWindow->requestRedraw();

	const QSize& oldSize = event->oldSize();
	int oldWidth = oldSize.width();
	int oldHeight = oldSize.height();

	int newWidth = size.width();
	int newHeight = size.height();

	double widthChangeRatio = double(newWidth) / double(oldWidth);
	double heigtChangeRatio = double(newHeight) / double(oldHeight);
	double aspectRatioChange = widthChangeRatio / heigtChangeRatio;
	QGLWidget::resizeEvent(event);
}

void EventAdapter::moveEvent(QMoveEvent* event)
{
	const QPoint& pos = event->pos();
	m_pGraphicsWindow->resized(pos.x(), pos.y(), width(), height());
	m_pGraphicsWindow->getEventQueue()->windowResize(pos.x(), pos.y(), width(), height());

	QGLWidget::moveEvent(event);
}

void EventAdapter::timerEvent(QTimerEvent *event)
{
	update();
}

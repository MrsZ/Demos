#ifndef EVENTADAPTER_H
#define EVENTADAPTER_H
#include <QtOpenGL/QGLWidget>
#include <osgViewer/View>
#include <QtGui/QKeyEvent>

class EventAdapter : public QGLWidget
{
	Q_OBJECT
public:
	EventAdapter(QWidget* parent=0,const char* name=0,const QGLWidget* shareWidget=0,Qt::WindowFlags flag=0);
	~EventAdapter(void);

	osgViewer::GraphicsWindow* getGraphicsWindow(){ return m_pGraphicsWindow.get(); }
	const osgViewer::GraphicsWindow* getGraphicsWindow()const{ return m_pGraphicsWindow.get(); }

protected:
	// Qt与OSG的事件传递;
	void setKeyboardModifiers(QInputEvent* event);
	virtual void resizeGL(int width,int height);
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent*);
	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_pGraphicsWindow;

private: 
	
};

#endif // EVENTADAPTER_H

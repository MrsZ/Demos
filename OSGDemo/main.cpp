#include "osgdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OSGDemo w;
	w.show();
	return a.exec();
}

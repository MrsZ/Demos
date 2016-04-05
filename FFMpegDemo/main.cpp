#include "ffmpegdemo.h"
#include <QtWidgets/QApplication>
#include "ButtonTest.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//FFMpegDemo w;
	ButtonTest w;
	w.show();
	return a.exec();
}

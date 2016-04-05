#include "ffplayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FFPlayer w;
	w.show();
	return a.exec();
}

#include <QApplication>
#include "qtdrawer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtDrawer w;
	w.showFullScreen();
	return a.exec();
}

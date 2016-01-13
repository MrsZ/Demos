#include <QtGui/QApplication>
#include <QTextCodec>
#include "qtdrawer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
	QtDrawer w;
	w.show();
	return a.exec();
}

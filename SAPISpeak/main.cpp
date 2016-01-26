#include <QApplication>
#include "textreader.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TextReader reader;
	reader.show();
	return a.exec();
}

#include "download.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
	FILE* file = fopen("D:/≤‚ ‘ ≤‚ ‘.doc", "wb+");
	if (!file)
	{
		return -1;
	}

	file = fopen("D:/≤‚ ‘  ≤‚ ‘.doc", "wb+");
	if (!file)
	{
		return -1;
	}

	file = fopen("D:/≤‚ ‘        ≤‚ ‘.doc", "wb+");
	if (!file)
	{
		return -1;
	}
	Download w;
	w.show();
	return a.exec();
}

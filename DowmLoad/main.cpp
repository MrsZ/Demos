#include <QtGui/QApplication>
#include <QTextCodec>
#include "FtpDownload.h"
#include "dowmload.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("GB2312");  
	QTextCodec::setCodecForLocale(codec);  
	QTextCodec::setCodecForCStrings(codec);  
	QTextCodec::setCodecForTr(codec);  
	FtpDownload w;
	w.show();
	return a.exec();
}

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>

#include <AVPlayer.h>
#include <WidgetRenderer.h>
#include <GraphicsItemRenderer.h>

#include <QFileDialog>

using namespace QtAV;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString fileName = QFileDialog::getOpenFileName(NULL, "Open File",
		"", "*");
	AVPlayer player;
	player.setFile(fileName);

	QGraphicsScene s;
	s.setSceneRect(0, 0, 800, 600);
	QGraphicsView v(&s);

	GraphicsItemRenderer g;
	g.resizeVideo(800, 600);
	s.addItem(&g);

	WidgetRenderer w;
	w.setWindowTitle(argv[1]);
	player.setRenderer(&w);
// 	w.resize(400, 300);
// 	w.resizeVideo(w.size());
	w.showMaximized();
	w.resizeVideo(w.size());
	player.play();
	return a.exec();
}

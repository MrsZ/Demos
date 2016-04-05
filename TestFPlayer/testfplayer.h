#ifndef TESTFPLAYER_H
#define TESTFPLAYER_H

#include <QtWidgets/QWidget>
#include "ui_testfplayer.h"

class TestFPlayer : public QWidget
{
	Q_OBJECT

public:
	TestFPlayer(QWidget *parent = 0);
	~TestFPlayer();

private:
	Ui::TestFPlayerClass ui;
};

#endif // TESTFPLAYER_H

#ifndef FFPLAYER_H
#define FFPLAYER_H

#include <QtWidgets/QWidget>
#include "ui_ffplayer.h"

class FFPlayer : public QWidget
{
	Q_OBJECT

public:
	FFPlayer(QWidget *parent = 0);
	~FFPlayer();

private:
	Ui::FFPlayerClass ui;
};

#endif // FFPLAYER_H

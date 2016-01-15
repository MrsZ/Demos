#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <sapi.h>
#include <sphelper.h>
#include <string>
#include "ui_TextReader.h"

class TextReader : public QWidget
{
	Q_OBJECT
public:
	TextReader(QWidget* parent = 0);
	~TextReader();

	enum PalyState{
		NO_STATE,
		PALYING,
		PAUSEING,
		NONE
	};

	void speak(const std::wstring& text, bool sync = false);
	void pause();
	void resume();
	void setVolume(int voice);

private slots:
	void slotSpeak();
	void slotComboBox();

private:
	void init();

private:
	Ui::TextReader ui;
	ISpVoice* m_pVoice;
	IEnumSpObjectTokens* m_pSpTokens;
	PalyState m_state;
};

#endif // TEXTREADER_H

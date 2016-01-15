#include "textreader.h"

TextReader::TextReader(QWidget* parent/* = 0*/)
: QWidget(parent)
{
	ui.setupUi(this);
	::CoInitialize(NULL);
	::CoCreateInstance(CLSID_SpVoice, NULL,
		CLSCTX_ALL, IID_ISpVoice, (void **)&m_pVoice);

	init();
	m_state = PalyState::NO_STATE;
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotSpeak()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotComboBox()));
}

TextReader::~TextReader()
{
	m_pVoice->Release();
	::CoUninitialize();
}

void TextReader::speak( const std::wstring& text, bool sync/* = false*/ )
{
	if (text == L"" || m_pVoice == NULL)
	{
		return;
	}
	if (sync)
	{
		m_pVoice->Speak(text.c_str(), SPEAKFLAGS::SPF_ASYNC, NULL);
	}
	else
	{
		m_pVoice->Speak(text.c_str(), SPEAKFLAGS::SPF_DEFAULT, NULL);
	}
}

void TextReader::init()
{
	ui.comboBox->clear();

	int ret = SpEnumTokens(SPCAT_VOICES,
		NULL, NULL, &m_pSpTokens);
	ISpObjectToken* pToken = NULL;
	ULONG count;
	m_pSpTokens->GetCount(&count);
	for (ULONG i = 0; i < count; ++i)
	{
		m_pSpTokens->Item(i, &pToken);
		WCHAR* pChar;
		pToken->GetId(&pChar);
		QString name = QString::fromWCharArray(pChar);
		ui.comboBox->addItem(name);
	}
}

void TextReader::slotSpeak()
{
	switch (m_state)
	{
	case NO_STATE:
		{
			speak(ui.textEdit->toPlainText().toStdWString(), true);

			ui.pushButton->setText(QString::fromLocal8Bit("ÔÝÍ£"));
			m_state = PalyState::PALYING;
		}
		break;
	case PALYING:
		{
			ui.pushButton->setText(QString::fromLocal8Bit("²¥·Å"));
			pause();
			m_state = PalyState::PAUSEING;
		}
		break;
	case PAUSEING:
		{
			ui.pushButton->setText(QString::fromLocal8Bit("ÔÝÍ£"));
			resume();
			m_state = PalyState::PALYING;
		}
		break;
	default:
		m_state = NO_STATE;
		break;
	}
}

void TextReader::pause()
{
	m_pVoice->Pause();
}

void TextReader::setVolume( int volume )
{
	m_pVoice->SetVolume(volume);
}

void TextReader::resume()
{
	m_pVoice->Resume();
}

void TextReader::slotComboBox()
{
	ISpObjectToken* pToken = NULL;
	m_pSpTokens->Item(ui.comboBox->currentIndex(), &pToken);
	m_pVoice->SetVoice(pToken);
	m_state = PalyState::NO_STATE;
}

#include <AVThread.h>
#include <AVThread_p.h>

namespace QtAV {
AVThread::AVThread(QObject *parent) :
	QThread(parent),d_ptr(new AVThreadPrivate())
{
}

AVThread::AVThread(AVThreadPrivate &d, QObject *parent)
    :QThread(parent),d_ptr(&d)
{
	qDebug("protected ctor");
}

AVThread::~AVThread()
{
}

void AVThread::wakeAll()
{
	d_ptr->not_empty_cond.wakeOne();
}

void AVThread::setPacketQueue(QAVPacketQueue *queue)
{
    d_ptr->packets = queue;
}


void AVThread::setDecoder(AVDecoder *decoder)
{
    d_ptr->dec = decoder;
}

AVDecoder* AVThread::decoder() const
{
    return d_ptr->dec;
}

void AVThread::setOutput(AVOutput *out)
{
    d_ptr->writer = out;
}

AVOutput* AVThread::output() const
{
    return d_ptr->writer;
}

}


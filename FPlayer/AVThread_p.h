#ifndef AVTHREAD_P_H
#define AVTHREAD_P_H

#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QtCore/QWaitCondition>

#include <QAVPacketQueue.h>
#include <AVDecoder.h>
#include <AVOutput.h>
#include <QtAV_Global.h>

namespace QtAV {
class AVDecoder;
class QAVPacket;
class AVThreadPrivate
{
public:
    AVThreadPrivate():packets(0),dec(0),writer(0) {}
    virtual ~AVThreadPrivate() {
        /*if (dec) {
            delete dec;
            dec = 0;
        }
        if (writer) {
            delete writer;
            writer = 0;
        }
        if (packets) {
            delete packets;
            packets = 0;
        }*/
    }
    void enqueue(const QAVPacket& pkt) {
        packets->enqueue(pkt);
        not_empty_cond.wakeAll();
    }


    QAVPacketQueue *packets;
    AVDecoder *dec;
    AVOutput *writer;
    QMutex mutex;
    QWaitCondition not_empty_cond;
};
}

#endif // AVTHREAD_P_H

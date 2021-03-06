#include <AVPlayer.h>

#include <qevent.h>
#include <qpainter.h>
#include <QApplication>

#include <AVInfo.h>
#include <VideoRenderer_p.h>
#include <AudioOutput.h>
#include <AudioThread.h>
#include <QAVPacket.h>
#include <AudioDecoder.h>
#include <VideoRenderer.h>

namespace QtAV {
AVPlayer::AVPlayer(QObject *parent) :
    QObject(parent),aFrame(0),renderer(0),vFrame(0),audio(0)
{
    avTimerId = -1;
    audio = new AudioOutput();
    audio_dec = new AudioDecoder();
    audio_thread = new AudioThread(this);
    audio_thread->setPacketQueue(&audio_queue);
    audio_thread->setDecoder(audio_dec);
    audio_thread->setOutput(audio);
	video_thread = 0;
}

AVPlayer::~AVPlayer()
{
    audio_thread->terminate();
    if (aFrame)
        av_free(aFrame);
    if (vFrame)
        av_free(vFrame);
    if (audio) {
        delete audio;
        audio = 0;
    }
    if (audio_dec) {
        delete audio_dec;
        audio_dec = 0;
    }

}

void AVPlayer::setRenderer(VideoRenderer *renderer)
{
    this->renderer = renderer;
}
//TODO: when is the end
bool AVPlayer::play(const QString& path)
{
    if (!path.isEmpty())
        filename = path;
    if (avTimerId > 0)
        killTimer(avTimerId);
    if (!avinfo.loadFile(filename)) {
		return false;
	}
	avinfo.dump();

	formatCtx = avinfo.formatContext();
    vCodecCtx = avinfo.videoCodecContext();
    aCodecCtx = avinfo.audioCodecContext();
    audio->setSampleRate(aCodecCtx->sample_rate);
    audio->setChannels(aCodecCtx->channels);
    audio->open();
	int videoStream = avinfo.videoStream();
	//audio
	//if (videoStream < 0)
	//	return false;

    AVStream *m_v_stream = formatCtx->streams[videoStream];
	qDebug("[AVFormatContext::duration = %lld]", avinfo.duration());
	qDebug("[AVStream::start_time = %lld]", m_v_stream->start_time);
    qDebug("[AVCodecContext::time_base = %d, %d, %.2f %.2f]", vCodecCtx->time_base.num, vCodecCtx->time_base.den
            ,1.0 * vCodecCtx->time_base.num / vCodecCtx->time_base.den
            ,1.0 / (1.0 * vCodecCtx->time_base.num / vCodecCtx->time_base.den));
	qDebug("[AVStream::avg_frame_rate = %d, %d, %.2f]", m_v_stream->avg_frame_rate.num, m_v_stream->avg_frame_rate.den
			,1.0 * m_v_stream->avg_frame_rate.num / m_v_stream->avg_frame_rate.den);
	qDebug("[AVStream::r_frame_rate = %d, %d, %.2f]", m_v_stream->r_frame_rate.num, m_v_stream->r_frame_rate.den
			,1.0 * m_v_stream->r_frame_rate.num / m_v_stream->r_frame_rate.den);
	qDebug("[AVStream::time_base = %d, %d, %.2f]", m_v_stream->time_base.num, m_v_stream->time_base.den
			,1.0 * m_v_stream->time_base.num / m_v_stream->time_base.den);
    frameNo=0;
    m_drop_count = 0;

	aFrame = av_frame_alloc();
	vFrame = av_frame_alloc();

    audio_dec->setCodecContext(aCodecCtx);
    audio_dec->setFrame(aFrame);
    audio_thread->setDecoder(audio_dec);
    audio_thread->start(QThread::HighestPriority);

	avTimerId = startTimer(1000/avinfo.frameRate());
    m_fps1.wake();

    return true;
}

void AVPlayer::timerEvent(QTimerEvent* e)
{
	if (e->timerId() != avTimerId)
		return;
	static AVPacket packet;
	static int videoStream = avinfo.videoStream();
    static int audioStream = avinfo.audioStream();
    while (av_read_frame(formatCtx, &packet) >=0 ) {
        if (packet.stream_index == audioStream) {
            QAVPacket pkt;
            pkt.data = QByteArray((const char*)packet.data, packet.size);
            pkt.duration = packet.duration;
            pkt.pts = packet.pts;
            audio_queue.enqueue(pkt);
            audio_thread->wakeAll();
            av_free_packet(&packet); //TODO: why is needed for static var?
        } else if (packet.stream_index == videoStream) {
            int len = avcodec_decode_video2(vCodecCtx, vFrame, &frameFinished, &packet);
            if (len < 0) {
                fprintf(stderr, "Error while decoding vFrame %d\n", frameNo);
                return;
            }
            if (frameFinished) {
                frameNo++;
                m_fps1.add(1);
                if(m_time_line.isNull())
                    m_time_line.start();
                //qDebug() << "m_time_line.elapsed()" << m_time_line.elapsed();
                if(packet.pts < m_time_line.elapsed()) {
                    printf("=====>SKIP[frameNo] %d [packet.pts] %lld\r", frameNo, packet.pts);
                    m_drop_count++;
                    //continue;
                }
                //qDebug("          [frameNo] %d" "[packet.pts] %d", frameNo, packet.pts);

                QByteArray data = renderer->scale(vCodecCtx, vFrame); //scaler?
                renderer->write(data);
            }
            av_free_packet(&packet);
            break;
        } else { //subtitle
            av_free_packet(&packet);
            continue;
        }
    }
}

}

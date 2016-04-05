#ifndef QAVVIDEORENDERER_P_H
#define QAVVIDEORENDERER_P_H

#include <qbytearray.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavcodec/avcodec.h"
#ifdef __cplusplus
}
#endif //__cplusplus

#define PIX_FMT AV_PIX_FMT_RGB32

namespace QtAV {
class VideoRendererPrivate
{
public:
    VideoRendererPrivate():width(0),height(0),pix_fmt(PIX_FMT),numBytes(0) {
    }

    void resizePicture(int width, int height);

    int width, height;
    AVPicture picture;
	enum AVPixelFormat pix_fmt;
    int numBytes;
    QByteArray data;
};
}

#endif // QAVVIDEORENDERER_P_H

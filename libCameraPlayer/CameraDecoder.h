#ifndef CAMERADECODER_H
#define CAMERADECODER_H
extern "C" {
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/fifo.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/time.h"
#include "libavutil/bprint.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavutil/tx.h"
#include "libswresample/swresample.h"
#include <libavcodec/avcodec.h>
#include "libavfilter/avfilter.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
}
#include "CameraFFmpeg.h"
#include <QObject>

namespace libFFmpegByQt {

// typedef struct DecoderContext{
//     AVCodecContext * codec_ctx=nullptr;
//     const AVCodec * codec=nullptr;
//     AVStream *stream=nullptr;
//     AVFrame* frame =nullptr;
// }DecoderContext;

class LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT CameraDecoder : public QObject
{
    Q_OBJECT
public:
    explicit CameraDecoder(QObject *parent = nullptr);
    bool initialize();
    void release();
    int open(AVFormatContext *fmt_ctx, AVMediaType type);
    AVFrame* read(AVPacket * pkt);
public:
    // std::unique_ptr<DecoderContext> ctx;
    AVCodecContext * codec_ctx=nullptr;
    const AVCodec * codec=nullptr;
    AVStream *stream=nullptr;
    AVFrame* frame =nullptr;
signals:
};

}


#endif // CAMERADECODER_H

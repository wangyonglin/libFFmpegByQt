#ifndef CAMERADEMUXER_H
#define CAMERADEMUXER_H
#include <QObject>
#include <QString>
#include <QDebug>

#include "CameraFFmpeg.h"
namespace libFFmpegByQt {

// typedef struct CameraDemuxerContext{

//     const AVInputFormat * iformat=NULL;
//     AVDictionary *dict;
//     QString url;
//     int width=1920;
//     int height=1080;
//     int framerate=60;
//     const AVCodec * video_decodec=NULL;
//     int video_stream_index=-1;
//     int audio_stream_index=-1;
//     AVStream * video_stream=NULL;
// }CameraDemuxerContext;

class LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT CameraDemuxer : public QObject
{
    Q_OBJECT
public:
    explicit CameraDemuxer(QObject *parent = nullptr);
    bool initialize();
    void release();
    int open(const QString & url);
    int read(AVPacket * pkt);
public:
    AVFormatContext *ifmt_ctx= nullptr;
    const AVInputFormat * iformat=NULL;
    AVDictionary *dict;

    int width=1920;
    int height=1080;
    int framerate=60;
    const AVCodec * video_decodec=NULL;
    int video_stream_index=-1;
    int audio_stream_index=-1;
    AVStream * video_stream=NULL;
};
}
#endif // CAMERADEMUXER_H

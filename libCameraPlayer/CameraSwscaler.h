#ifndef CAMERASWSCALER_H
#define CAMERASWSCALER_H

#include <QObject>
#include <QImage>
#include "CameraFFmpeg.h"

typedef enum AVPixelFormat QFFmpegPixelFormat;
namespace libFFmpegByQt {
class LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT CameraSwscaler : public QObject
{
    Q_OBJECT
public:

    explicit CameraSwscaler(QObject *parent = nullptr);
    void ReleaseAll();
    int ImageAllocate(AVCodecContext *dec_ctx);
    uint8_t *dstImagedata[4];
    int  dstImagelinesize[4];
    int dstImagesize;
    int converting(AVFrame *frame);
    int AVFrame2YUV420P(AVFrame *frame);
    int AVFrame2RGBA(AVFrame *frame);
    void SetFormat(QFFmpegPixelFormat  pix_fmt=AV_PIX_FMT_YUV420P);
private:
    AVCodecContext * dec_ctx;
    QFFmpegPixelFormat  dst_pix_fmt= AV_PIX_FMT_NONE;

    //enum AVPixelFormat src_pix_fmt = AV_PIX_FMT_YUV420P, dst_pix_fmt = AV_PIX_FMT_RGB24;


};
}
#endif // CAMERASWSCALER_H

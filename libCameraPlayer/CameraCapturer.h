#ifndef CAMERACAPTURER_H
#define CAMERACAPTURER_H
#include "CameraDemuxer.h"
#include "CameraDecoder.h"
#include "CameraSwscaler.h"
#include "CameraThread.h"
#include <QObject>

#include "CameraFFmpeg.h"


namespace libFFmpegByQt {
class LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT CameraCapturer : public CameraThread
{

    Q_OBJECT
public:
    explicit CameraCapturer(QObject *parent = nullptr);
    void open(const QString &url);
    void stop();
public slots:
signals:
    void sigFirst( uint8_t * data[],int w,int h);
    void newFrame();
private:
    CameraDemuxer *demux;
    CameraDecoder *video_decoder;
    CameraSwscaler *videoswscaler;
protected:
    virtual void loop() override;
};
}
#endif // CAMERACAPTURER_H

#include "CameraCapturer.h"
#include "qdebug.h"

libFFmpegByQt::CameraCapturer::CameraCapturer(QObject *parent)
    : CameraThread{parent}
{

    demux=new CameraDemuxer(parent);
    video_decoder= new CameraDecoder(parent);
    videoswscaler= new CameraSwscaler(parent);
    demux->initialize();
    video_decoder->initialize();
}



void libFFmpegByQt::CameraCapturer::open(const QString &url)
{
    int ret =0;
    ret=demux->open(url);
    video_decoder->open(demux->ifmt_ctx,AVMEDIA_TYPE_VIDEO);
    videoswscaler->SetFormat(AV_PIX_FMT_YUV420P);
    videoswscaler->ImageAllocate(video_decoder->codec_ctx);
     emit sigFirst(this->videoswscaler->dstImagedata,video_decoder->codec_ctx->width, video_decoder->codec_ctx->height);
    if(ret>=0){
        start();
    }
}

void libFFmpegByQt::CameraCapturer::stop()
{
    stop();
    video_decoder->release();
    demux->release();
}




void libFFmpegByQt::CameraCapturer::loop()
{
    AVPacket pkt;
    QThread::msleep(100);
    if(demux->read(&pkt)==0){
        if (pkt.stream_index == demux->video_stream_index)
        {
            AVFrame* frame= video_decoder->read(&pkt);
            if(frame){

                if(videoswscaler->converting(frame)==0){
                emit newFrame();
                }

                av_frame_free(&frame);
            }

        }
        av_packet_unref(&pkt);
    }
}

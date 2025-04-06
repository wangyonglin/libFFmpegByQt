#ifndef CAMERAFFMPEG_H
#define CAMERAFFMPEG_H
extern "C" {
#include <libavcodec/avcodec.h>
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

#include "libavfilter/avfilter.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
}

#include <QtCore/qglobal.h>

#if defined(LIBFFMPEGBYQT_LIBCAMERAPLAYER_LIBRARY)
#  define LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT Q_DECL_EXPORT
#else
#  define LIBFFMPEGBYQT_LIBCAMERAPLAYER_EXPORT Q_DECL_IMPORT
#endif
#endif // CAMERAFFMPEG_H

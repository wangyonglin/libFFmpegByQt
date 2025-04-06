# libFFmpegByQt
TEMPLATE = subdirs

 SUBDIRS = \
    Examples \
    libCameraPlayer
    #libVideoPlayer

 # where to find the sub projects - give the folders
 libCameraPlayer.subdir = libCameraPlayer
 #libVideoPlayer.subdir = libVideoPlayer

 # what subproject depends on others
 Examples.depends = libCameraPlayer
 #Examples.depends = libVideoPlayer

 Examples.subdir  = examples/CameraPlayer

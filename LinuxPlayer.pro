
TARGET = LinuxPlayer
CONFIG += c++11

HEADERS += \
    sn_avdecoder.h \
    sn_video_frame_provider.h \
    sn_video_packet_list.h

SOURCES += \
    main.cpp \
    sn_avdecoder.cpp \
    sn_video_frame_provider.cpp \
    sn_video_packet_list.cpp

INCLUDEPATH +=/usr/local/include/
LIBS +=/usr/local/lib/libavcodec.so\
    /usr/local/lib/libavfilter.so\
    /usr/local/lib/libavformat.so\
    /usr/local/lib/libswscale.so\
    /usr/local/lib/libavutil.so\


INCLUDEPATH +=/usr/local/include/opencv2\
              /usr/local/include/opencv
LIBS+=/usr/local/lib/libopencv_highgui.so\
      /usr/local/lib/libopencv_core.so\
      /usr/local/lib/libopencv_imgproc.so\

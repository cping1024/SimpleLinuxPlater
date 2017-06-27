#include <stdio.h>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sn_avdecoder.h>

void HandleDecodeCallBack(void *buffer, void *frame, void *caller, int width, int height)
{
    AVFrame *avframe = static_cast<AVFrame*>(frame);
    if (!avframe) {
        return ;
    }

    cv::Mat image = cv::Mat(height, width, CV_8UC3, buffer, avframe->linesize[0]);
    if (!image.data) {
        return;
    }

    cv::imshow("frame", image);
    cv::waitKey(1);
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Args error!\n");
        return -1;
    }

    const std::string& url = std::string(argv[1]);
    SN_AVDecoder* decoder = new SN_AVDecoder();
    if (!decoder) {
        return -1;
    }

    decoder->setStreamUrl(url);
    decoder->setCallBack(HandleDecodeCallBack, NULL);

    int ret = decoder->open();
    if (ret != 0) {
        return ret;
    }

    ret = decoder->start();
    if (ret != 0) {
        return ret;
    }

    printf("Enter any key to exit app.\n");
    getchar();

    decoder->stop();
    decoder->close();
    delete decoder;

    return 0;
}

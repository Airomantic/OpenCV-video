#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//https://blog.csdn.net/qq_41854650/article/details/97276690 被申请了专利，调用会报错，退回老版本可以
//#include <opencv2/xfeatures2d.hpp>
//namespace
using namespace std;
using namespace cv;
//using namespace cv::xfeatures2d;

int main() {
    //调用电脑摄像头
    cv::VideoCapture capture(0);

    if (!capture.isOpened()) {
        std::cout << "open camera error!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (1) {
        capture >> frame;
        if (frame.empty()) {
            std::cout << "capture empty frame" << std::endl;
            continue;
        }

        cv::Mat shrink_frame;
        cv::resize(frame, shrink_frame,
                   cv::Size(frame.cols / 1.5, frame.rows / 1.5),//控制摄像大小
                   0, 0, 3);

        cv::imshow("real time monitor", shrink_frame);

        int key = cv::waitKey(1);
        if (key == 'q') {
            break;
        }
    }
    return 0;
}
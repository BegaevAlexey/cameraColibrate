#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    // open camera
    cv::VideoCapture cap;
    cap.open("rtsp://admin:admin@192.168.0.112");

    // load frame
    cv::Mat imageRGB;
    cap >> imageRGB;

    if (imageRGB.empty()) {
        std::cerr << "Error: no open the camera!" << std::endl;
        return -1;
    }

    // find corners on chessboard
    cv::Size coutCorners(9, 6);
    std::vector<cv::Point2f> points;
    bool flag = cv::findChessboardCorners(imageRGB, coutCorners,points, cv::CALIB_CB_FAST_CHECK);

    // draw corners on chessboard
    cv::drawChessboardCorners(imageRGB, coutCorners, points, flag);

    // show image
    cv::namedWindow("Ip Camera #112", cv::WINDOW_GUI_NORMAL);
    cv::imshow("Ip Camera #112", imageRGB);

    cv::waitKey(0);

    return 0;
}
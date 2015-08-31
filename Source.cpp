#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{ 
    std::string imgPathStr("D:\\openCV_build\\doc\\opencv-logo2.png");
    cv::Mat img = cv::imread(imgPathStr,-1); // Read image
    cv::imshow("img",img);
    cv::waitKey();
    std::system("PAUSE");
    return 0;
}
#include <opencv2/opencv.hpp>

void ocmu_gradient(cv::Mat img, cv::Mat_<double> &Gx, cv::Mat_<double> &Gy);

cv::Mat_<uchar> ocmu_imclose(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element);

cv::Mat_<uchar> ocmu_imopen(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element);

cv::Mat_<uchar> ocmu_maxconnecteddomain(cv::Mat_<uchar> binImg);
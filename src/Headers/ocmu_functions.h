#include <opencv2/opencv.hpp>

struct connectedDomainStruct{
     cv::Mat_<uchar> targetRegion;
	 int xBegPos;
	 int yBegPos;
	 int xEndPos;
	 int yEndPos;  
};

void ocmu_gradient(cv::Mat img, cv::Mat_<double> &Gx, cv::Mat_<double> &Gy);

cv::Mat_<uchar> ocmu_imclose(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element);

cv::Mat_<uchar> ocmu_imopen(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element);

cv::Mat_<uchar> ocmu_maxconnecteddomain(cv::Mat_<uchar> binImg);

connectedDomainStruct ocmu_connecteddomain(cv::Mat_<uchar> binImg, int idx = 0);
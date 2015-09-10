#include <opencv2/opencv.hpp>
#include <iostream>
#include "..\Headers\ocmu_functions.h"

void demo_ocmu_gradient()
{
	cv::Mat_<uchar> testMat = cv::Mat::zeros(5, 6, CV_8U);
	cv::randu(testMat, cv::Scalar(0), cv::Scalar(256));
	std::cout<<"testMat = "<<testMat<<std::endl;
	cv::Mat_<double> Gx; 
	cv::Mat_<double> Gy;
	ocmu_gradient(testMat, Gx, Gy);

	std::cout<<"Gx = "<<Gx<<std::endl;
	std::cout<<"Gy = "<<Gy<<std::endl;

}


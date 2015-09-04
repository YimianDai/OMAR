// Demo for the attributes and functions of cv::Mat

#include <opencv2/opencv.hpp>
#include <iostream>

void cvmatdemo()
{ 
    /*Is it OK to assign cv::Mat_<double> values to cv::Mat_<float> object ?*/	
	cv::Mat_<double> doubleMat = cv::Mat::zeros(4, 5, CV_64F);
	cv::randn(doubleMat, cv::Scalar(128), cv::Scalar(10));
	cv::Mat_<float> floatMat = doubleMat;
	std::cout<<"doubleMat = "<<std::endl<<doubleMat<<std::endl;
	std::cout<<"floatMat = "<<std::endl<<floatMat<<std::endl;    
}
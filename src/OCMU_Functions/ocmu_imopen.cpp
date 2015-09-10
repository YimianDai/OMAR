#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat_<uchar> ocmu_imopen(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element)
{
	cv::Mat erodeImg, openImg;
	cv::erode(binImg, erodeImg, element);
	cv::dilate(erodeImg, openImg, element);	
	return openImg;
}
#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat_<uchar> ocmu_imclose(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element)
{
	cv::Mat dilateImg, closeImg;
	cv::dilate(binImg, dilateImg, element);
	cv::erode(dilateImg, closeImg, element);
	return closeImg;
}
#include <opencv2/opencv.hpp>
#include <iostream>

void demo_resize()
{
	double data[] = {1, 2, 3, 4};
	cv::Mat A(2, 2, CV_64FC1, data);
	std::cout<<"Before: A = "<<A<<std::endl;
	cv::resize(A, A, cv::Size(4, 4), cv::INTER_LINEAR);
	std::cout<<"resize bigger: A = "<<A<<std::endl;
	cv::resize(A, A, cv::Size(2, 2), cv::INTER_LINEAR);
	std::cout<<"resize smaller: A = "<<A<<std::endl;
}
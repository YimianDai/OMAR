#include <opencv2/opencv.hpp>
#include <iostream>

void demo_setTo()
{
	uchar data[] = {1,2,3,1,2,3,1,2,3};
	//cv::Mat A(9, 1, CV_8UC1, data); // 1, 9 is also OK
	cv::Mat A(1, 9, CV_8UC1, data);
	std::cout<<"Before: A = "<<A<<std::endl;
	A.setTo(0, A == 1);
	std::cout<<"After: A = "<<A<<std::endl;
}
// Demo for the attributes and functions of std::string

#include <opencv2/opencv.hpp>
#include <iostream>

void stringdemo()
{ 
    std::string imgPathStr("D:\\openCV_build\\doc\\opencv-logo2.png");

	/*Transfer std::string object into char array*/
	const char* imgPathCharArr = imgPathStr.c_str();
	std::cout<<"imgPathCharArr = "<<imgPathCharArr<<std::endl; 
}
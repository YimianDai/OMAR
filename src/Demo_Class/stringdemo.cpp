// Demo for the attributes and functions of std::string

#include <opencv2/opencv.hpp>
#include <iostream>

extern std::string projectPath;

void stringdemo()
{ 
	std::string imgPathStr = projectPath + "images\\opencv-logo2.png";

	/*Transfer std::string object into char array*/
	const char* imgPathCharArr = imgPathStr.c_str();
	std::cout<<"imgPathCharArr = "<<imgPathCharArr<<std::endl; 
}
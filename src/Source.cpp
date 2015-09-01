#include <opencv2/opencv.hpp>
#include <iostream>
#include "Headers\class_demo.h"

int main(int argc, char **argv)
{ 
 //   std::string imgPathStr("D:\\openCV_build\\doc\\opencv-logo2.png");
 //   cv::Mat img = cv::imread(imgPathStr,-1); // Read image
 //   cv::imshow("img",img);
 //   cv::waitKey();

	//// Transfer std::string object into char array
	//const char* imgPathCharArr = imgPathStr.c_str();
	//std::cout<<"imgPathCharArr = "<<imgPathCharArr<<std::endl;
	    
	/*Demos for Attributes and Functions of Classes*/
	stringdemo();

	/*Demos for Attributes and Functions of Classes*/
	matdemo();

    std::system("PAUSE");
    return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>
#include "..\Headers\ocmu_functions.h"

extern std::string projectPath;

void demo_ocmu_imclose()
{
	std::string imgPathStr = projectPath + "images\\opencv-logo2.png";
	cv::Mat_<uchar> img = cv::imread(imgPathStr, CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat_<uchar> binImg = img > 128;
	//cv::imshow("binImg", binImg);
	//cv::waitKey();

	int erosion_size = 20;
	int erosion_type = cv::MORPH_RECT;	
	cv::Size kernelSize = cv::Size(2*erosion_size + 1, 2*erosion_size+1);
	cv::Point anchorPoint = cv::Point(erosion_size, erosion_size);
	cv::Mat element = cv::getStructuringElement(erosion_type, kernelSize, \
		anchorPoint);

	int elementType = element.type();
	std::cout<<"elementType = "<<elementType<<std::endl;

	//cv::Mat dilateImg, closeImg;
	//cv::dilate(binImg, dilateImg, element);
	//cv::erode(dilateImg, closeImg, element);
	//cv::imshow("binImg", binImg);
	//cv::imshow("dilateImg", dilateImg);	
	//cv::imshow("closeImg", closeImg);
	//cv::waitKey();

	cv::Mat_<uchar> closeImg = ocmu_imclose(binImg, element);	
	cv::Mat_<uchar> openImg = ocmu_imopen(binImg, element);
	cv::imshow("closeImg", closeImg);
	cv::imshow("openImg", openImg);
	cv::waitKey();

	cv::Mat_<uchar> morphCloseImg, morphOpenImg;
	morphologyEx(binImg, morphCloseImg, cv::MORPH_CLOSE, element);
	morphologyEx(binImg, morphOpenImg, cv::MORPH_OPEN, element);
	cv::imshow("morphCloseImg", morphCloseImg);
	cv::imshow("morphOpenImg", morphOpenImg);
	cv::waitKey();
}


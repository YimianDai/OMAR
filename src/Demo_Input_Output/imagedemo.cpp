// Demo for operations of images

#include <opencv2/opencv.hpp>
#include <iostream>

extern std::string projectPath;

void imagedemo()
{ 
	/*Read image*/
	std::string imgPathStr = projectPath + "images\\opencv-logo2.png";
	cv::Mat img = cv::imread(imgPathStr,-1);

	/*imshow*/
	cv::imshow("img",img);
	cv::waitKey();

	/*Check if the image is readed correctly*/
	if (!img.data) {
		std::cout<<"img is not created."<<std::endl;
	} else {
		std::cout<<"img is readed correctly."<<std::endl;
	}
	std::string wrongImgPathStr = projectPath + "images\\wrong.png";
	cv::Mat wrongImg = cv::imread(wrongImgPathStr,-1);
	if (!wrongImg.data) {
		std::cout<<"wrongImage is not created."<<std::endl;
	} else {
		std::cout<<"wrongImage is readed correctly."<<std::endl;
	}

	/*Write image*/
	std::string imwritePath = projectPath + "outputs\\imwriteDemo.jpg";
	cv::imwrite(imwritePath, img);

}
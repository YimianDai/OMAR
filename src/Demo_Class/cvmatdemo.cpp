// Demo for the attributes and functions of cv::Mat

#include <opencv2/opencv.hpp>
#include <iostream>

extern std::string projectPath;

void cvmatdemo()
{ 
	/*Read image*/
	std::string imgPathStr = projectPath + "images\\opencv-logo2.png";
	cv::Mat img = cv::imread(imgPathStr,-1);

	/*Is it OK to assign cv::Mat_<double> values to cv::Mat_<float> object ?*/	
	cv::Mat_<double> doubleMat = cv::Mat::zeros(4, 5, CV_64F);
	cv::randn(doubleMat, cv::Scalar(128), cv::Scalar(10));
	cv::Mat_<float> floatMat = doubleMat;
	std::cout<<"doubleMat = "<<std::endl<<doubleMat<<std::endl;
	std::cout<<"floatMat = "<<std::endl<<floatMat<<std::endl;   

	/*Get rows and columns of the matrix*/
	int matRows = doubleMat.rows;
	int matCols = doubleMat.cols;
	std::cout<<"matRows = "<<matRows<<std::endl;
	std::cout<<"matCols = "<<matCols<<std::endl;

	/*Get channels of the matrix*/
	int matChannels = doubleMat.channels();
	std::cout<<"matChannels = "<<matChannels<<std::endl;
	int imgChannels = img.channels();
	std::cout<<"imgChannels = "<<imgChannels<<std::endl;
}
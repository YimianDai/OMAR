// Demo for operations of MATLAB .mat files

#include <opencv2/opencv.hpp>
#include <iostream>

extern std::string projectPath;

void matlabmatdemo()
{
	/*Load MATLAB .mat file via YML file*/	
	std::string ymlPath = projectPath + "data\\smallIdArr.yml";
	cv::FileStorage fsDemo(ymlPath, cv::FileStorage::READ);
	cv::Mat smallIdArr;
	fsDemo["smallIdArr"] >> smallIdArr;
	fsDemo.release();
	std::cout<<"smallIdArr = "<<std::endl<<smallIdArr<<std::endl;
}
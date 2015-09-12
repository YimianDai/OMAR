#include <opencv2/opencv.hpp>
#include <iostream>

void demo_sort_sortIdx()
{
	int testArrLen = 5;
	cv::Mat_<int> testArr = cv::Mat::zeros(1, testArrLen, CV_32S);
	testArr(0,0) = 87;
	testArr(0,1) = 65;
	testArr(0,2) = 98;
	testArr(0,3) = 12;
	testArr(0,4) = 55;

	cv::Mat_<int> sortArr, sortIdxArr;
	cv::sort(testArr, sortArr, CV_SORT_DESCENDING);
	cv::sortIdx(testArr, sortIdxArr, CV_SORT_DESCENDING);
	
	std::cout<<"testArr = "<<testArr<<std::endl;
	std::cout<<"sortArr = "<<sortArr<<std::endl;
	std::cout<<"sortIdxArr = "<<sortIdxArr<<std::endl;
}


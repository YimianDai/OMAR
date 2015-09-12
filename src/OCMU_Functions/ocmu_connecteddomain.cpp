#include <opencv2/opencv.hpp>
#include <iostream>
#include "..\Headers\ocmu_functions.h"
// Input variables:
// idx: index of the connected domain areas to select return which connected domain
//      e.g., idx = 0 for the maximum connected domain
connectedDomainStruct ocmu_connecteddomain(cv::Mat_<uchar> binImg, int idx)
{	
	connectedDomainStruct targetStruct;	

	// 查找轮廓，对应连通域 
	cv::Mat_<uchar> contourImg;
	binImg.copyTo(contourImg);
	std::vector<std::vector<cv::Point>> contourVecs;  
	cv::findContours(contourImg, contourVecs,CV_RETR_EXTERNAL, \
		CV_CHAIN_APPROX_NONE);

	int contourVecLen = contourVecs.size();
	if (contourVecLen > 0) { // 存在多个连通域，寻找最大连通域 
		cv::Mat_<double> areaArr = cv::Mat::zeros(1, contourVecLen, CV_64F);
		for(int i = 0; i < contourVecLen; i++) {  
			areaArr(0, i) = cv::contourArea(contourVecs[i]);  
		}  
				
		// 排序
		cv::Mat_<double> sortArr;
		cv::Mat_<int> sortIdxArr;
		cv::sort(areaArr, sortArr, CV_SORT_DESCENDING);
		cv::sortIdx(areaArr, sortIdxArr, CV_SORT_DESCENDING);		
		int origIdx = sortIdxArr(0, idx);
		std::vector<cv::Point> targetContour = contourVecs[origIdx]; 
		
		// 将轮廓转为矩形框  
		cv::Rect targetRect = cv::boundingRect(targetContour);  
		int xBegPos = targetRect.y;
		int yBegPos = targetRect.x;
		int xEndPos = xBegPos + targetRect.height;
		int yEndPos = yBegPos + targetRect.width;

		targetStruct.targetRegion = binImg(cv::Range(xBegPos, xEndPos), \
			cv::Range(yBegPos, yEndPos));
		targetStruct.xBegPos = xBegPos;
		targetStruct.yBegPos = yBegPos;
		targetStruct.xEndPos = xEndPos;
		targetStruct.yEndPos = yEndPos;

	}
	return targetStruct;
}
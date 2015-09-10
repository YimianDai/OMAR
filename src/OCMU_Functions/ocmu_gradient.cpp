#include <opencv2/opencv.hpp>
#include <iostream>

void ocmu_gradient(cv::Mat img, cv::Mat_<double> &Gx, cv::Mat_<double> &Gy)
{
	cv::Mat_<double> dImg;
	img.convertTo(dImg, CV_64F);
	int rows = img.rows;
	int cols = img.cols;

	cv::Mat_<double> xTopVec = dImg.col(1) - dImg.col(0);
	cv::Mat_<double> xBotVec = dImg.col(cols-1) - dImg.col(cols-2);
	cv::Mat_<double> xForwMat = dImg(cv::Range(0, rows), cv::Range(0, cols-2));
	cv::Mat_<double> xBackMat = dImg(cv::Range(0, rows), cv::Range(2, cols));
	cv::Mat_<double> centGx = (xBackMat - xForwMat) / 2;
	cv::Mat_<double> tmpGx = cv::Mat::zeros(rows, cols, CV_64F);
	for (int i = 1; i < cols-1; i++) {
		centGx.col(i-1).copyTo(tmpGx.col(i));
	}
	xTopVec.copyTo(tmpGx.col(0));
	xBotVec.copyTo(tmpGx.col(cols-1));

	cv::Mat_<double> yTopArr = dImg.row(1) - dImg.row(0);
	cv::Mat_<double> yBotArr = dImg.row(rows-1) - dImg.row(rows-2);
	cv::Mat_<double> yForwMat = dImg(cv::Range(0, rows-2), cv::Range(0, cols));
	cv::Mat_<double> yBackMat = dImg(cv::Range(2, rows), cv::Range(0, cols));
	cv::Mat_<double> centGy = (yBackMat - yForwMat) / 2;
	cv::Mat_<double> tmpGy = cv::Mat::zeros(rows, cols, CV_64F);
	for (int i = 1; i < rows-1; i++) {
		centGy.row(i-1).copyTo(tmpGy.row(i));
	}
	yTopArr.copyTo(tmpGy.row(0));
	yBotArr.copyTo(tmpGy.row(rows-1));

	Gx = tmpGx;
	Gy = tmpGy;
}
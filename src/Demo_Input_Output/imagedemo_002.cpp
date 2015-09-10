// Demo for operations of images

#include <opencv2/opencv.hpp>
#include <iostream>

extern std::string projectPath;

void imagedemo_002()
{ 
	/* 002 - 图像的读取、显示和写入 */
	std::string imgPathStr = projectPath + "images\\opencv-logo2.png";
	cv::Mat img_COLOR_Mat = cv::imread(imgPathStr, CV_LOAD_IMAGE_COLOR);
	cv::Mat img_GRAYSCALE_Mat = cv::imread(imgPathStr, CV_LOAD_IMAGE_GRAYSCALE);
	const char* fileNameCharArr = imgPathStr.c_str();
	IplImage* img_COLOR_IplImage = cvLoadImage(fileNameCharArr, \
		CV_LOAD_IMAGE_COLOR);
	IplImage* img_GRAYSCALE_IplImage = cvLoadImage(fileNameCharArr, \
		CV_LOAD_IMAGE_GRAYSCALE);
	CvMat* img_COLOR_CvMat = cvLoadImageM(fileNameCharArr, \
		CV_LOAD_IMAGE_COLOR);
	CvMat* img_GRAYSCALE_CvMat = cvLoadImageM(fileNameCharArr, \
		CV_LOAD_IMAGE_GRAYSCALE);

	std::string title_COLOR_Mat = "cv::Mat COLOR";
	std::string title_GRAYSCALE_Mat = "cv::Mat GRAYSCALE";
	std::string title_COLOR_CvMat = "CvMat COLOR";
	std::string title_GRAYSCALE_CvMat = "CvMat GRAYSCALE";
	std::string title_COLOR_IplImage = "IplImage COLOR";
	std::string title_GRAYSCALE_IplImage = "IplImage GRAYSCALE";
	const char* char_title_COLOR_CvMat = title_COLOR_CvMat.c_str();
	const char* char_title_GRAYSCALE_CvMat = title_GRAYSCALE_CvMat.c_str();
	const char* char_title_COLOR_IplImage = title_COLOR_IplImage.c_str();
	const char* char_title_GRAYSCALE_IplImage = title_COLOR_IplImage.c_str();
	cv::imshow(title_COLOR_Mat, img_COLOR_Mat); 
	cv::waitKey();	
	cv::imshow(title_GRAYSCALE_Mat, img_GRAYSCALE_Mat);
	cv::waitKey();
	cvShowImage(char_title_COLOR_CvMat, img_COLOR_CvMat);
	cv::waitKey();
	cvShowImage(char_title_GRAYSCALE_CvMat, img_GRAYSCALE_CvMat);
	cv::waitKey();
	cvShowImage(char_title_COLOR_IplImage, img_COLOR_IplImage);
	cv::waitKey();
	cvShowImage(char_title_GRAYSCALE_IplImage, img_GRAYSCALE_IplImage);
	cv::waitKey();

	/*Release Memory*/
	cvReleaseImage(&img_COLOR_IplImage);
	cvReleaseImage(&img_GRAYSCALE_IplImage);
	cvReleaseMat(&img_COLOR_CvMat);
	cvReleaseMat(&img_GRAYSCALE_CvMat);

	/*Check if the image is readed correctly*/
	if (!img_COLOR_Mat.data) {
		std::cout<<"img_COLOR_Mat is not created."<<std::endl;
	} else {
		std::cout<<"img_COLOR_Mat is readed correctly."<<std::endl;
	}
	std::string wrongImgPathStr = projectPath + "images\\wrong.png";
	cv::Mat wrongImg = cv::imread(wrongImgPathStr,-1);
	if (!wrongImg.data) {
		std::cout<<"wrongImage is not created."<<std::endl;
	} else {
		std::cout<<"wrongImage is readed correctly."<<std::endl;
	}

	/*Write image*/
	std::string imwriteMatPath = projectPath + "outputs\\imwriteDemo_Mat.jpg";
	bool flag_Mat = cv::imwrite(imwriteMatPath, img_GRAYSCALE_Mat);
	std::cout<<"flag_Mat = "<<flag_Mat<<std::endl;

	std::string tmp_CvMatPath = projectPath + "outputs\\imwriteDemo_CvMat.jpg";
	const char* imwriteCvMatPath = tmp_CvMatPath.c_str();
	//int flag_CvMat = cvSaveImage(imwriteCvMatPath, img_GRAYSCALE_CvMat);
	//std::cout<<"flag_CvMat = "<<flag_CvMat<<std::endl;

	std::string tmp_IplImagePath = projectPath + "outputs\\imwriteDemo_IplImage.jpg";
	const char* imwriteIplImagePath = tmp_IplImagePath.c_str();
	//int flag_IplImage = cvSaveImage(imwriteIplImagePath, img_GRAYSCALE_IplImage);
	//std::cout<<"flag_IplImage = "<<flag_IplImage<<std::endl;

}
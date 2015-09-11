# 抠取最大连通区域的 OpenCV 实现 

今天，工作上需要用 OpenCV/C++ 实现一下抠取二值图像的最大连通区域，看到一篇很好的博文 [使用OpenCV查找二值图中最大连通区域][使用OpenCV查找二值图中最大连通区域]。在该文的帮助下，实现了抠取二值图像的最大连通区域的功能。
在 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 里，我在 OCMU_Functions 文件夹下添加了 ocmu_maxconnecteddomain.cpp 函数，给出了 抠取二值图像的最大连通区域的 OpenCV 实现，具体 Demo 可以运行 Demo_OCMU_Functions 文件夹下的 demo_ocmu_maxconnecteddomain.cpp 函数。

需要注意的是，有些极端情况，会返回一个空矩阵，在使用的时候需要注意，这个在函数和 Demo 里都给出了相应的处理。还有一点，代码里可能会混淆的是 x-y 究竟代表水平还是竖直的问题。这是因为，我理解的 x 方向是图像的竖直方向，y 方向是图像的水平方向，刚好跟 OpenCV 相反，OpenCV 的 x 方向是图像的水平方向，y 方向是图像的数值方向。这一点，MATLAB figure 窗口的 Data Cursor 里的 x-y 坐标值也跟 OpenCV 一致。但只要是我写的代码，还是按照我自己习惯的思维来。

为了方便起见，ocmu_maxconnecteddomain.cpp 函数内容如下：
```C++
#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat_<uchar> ocmu_maxconnecteddomain(cv::Mat_<uchar> binImg)
{   
    cv::Mat_<uchar> maxRegion; // Returned matrix;

    // 查找轮廓，对应连通域 
    cv::Mat_<uchar> contourImg;
    binImg.copyTo(contourImg);
    std::vector<std::vector<cv::Point>> contourVecs;  
    cv::findContours(contourImg, contourVecs,CV_RETR_EXTERNAL, \
        CV_CHAIN_APPROX_NONE);
         
    if (contourVecs.size() > 0) { // 存在多个连通域，寻找最大连通域 
        double maxArea = 0;  
        std::vector<cv::Point> maxContour;  
        for(size_t i = 0; i < contourVecs.size(); i++) {  
            double area = cv::contourArea(contourVecs[i]);  
            if (area > maxArea) {  
                maxArea = area;  
                maxContour = contourVecs[i];  
            }  
        }  

        // 将轮廓转为矩形框  
        cv::Rect maxRect = cv::boundingRect(maxContour);  
        int xBegPos = maxRect.y;
        int yBegPos = maxRect.x;
        int xEndPos = xBegPos + maxRect.height;
        int yEndPos = yBegPos + maxRect.width;

        maxRegion = binImg(cv::Range(xBegPos, xEndPos), \
            cv::Range(yBegPos, yEndPos));
    }

    return maxRegion;
}
```

Demo demo_ocmu_maxconnecteddomain.cpp 的内容如下：
```C++
#include <opencv2/opencv.hpp>
#include <iostream>
#include "..\Headers\ocmu_functions.h"

extern std::string projectPath;

void demo_ocmu_maxconnecteddomain()
{
    std::string imgPathStr = projectPath + "images\\opencv-logo2.png";
    cv::Mat_<uchar> img = cv::imread(imgPathStr, CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat_<uchar> binImg = img < 128;
    cv::imshow("binImg 1", binImg);

    // 查找轮廓，对应连通域 
    cv::Mat_<uchar> contourImg;
    binImg.copyTo(contourImg);
    std::vector<std::vector<cv::Point>> contourVecs;  
    cv::findContours(contourImg, contourVecs,CV_RETR_EXTERNAL, \
        CV_CHAIN_APPROX_NONE);  

    // 寻找最大连通域  
    double maxArea = 0;  
    std::vector<cv::Point> maxContour;  
    for(size_t i = 0; i < contourVecs.size(); i++) {  
        double area = cv::contourArea(contourVecs[i]);  
        if (area > maxArea) {  
            maxArea = area;  
            maxContour = contourVecs[i];  
        }  
    }  

    // 将轮廓转为矩形框  
    cv::Rect maxRect = cv::boundingRect(maxContour);    

    // 显示连通域  
    cv::Mat result1, result2;  
    binImg.copyTo(result1);  
    binImg.copyTo(result2);  
    for (size_t i = 0; i < contourVecs.size(); i++) {  
        cv::Rect r = cv::boundingRect(contourVecs[i]);  
        cv::rectangle(result1, r, cv::Scalar(255));  
    }  

    cv::rectangle(result2, maxRect, cv::Scalar(255));  

    cv::Mat_<uchar> maxRegion = ocmu_maxconnecteddomain(binImg);

    if (!maxRegion.data) {
        std::cout<<"Maximum connected region does not exist."<<std::endl;       
    } else {
        std::cout<<"Maximum connected region exists."<<std::endl;
    }

    cv::imshow("all regions", result1) ;  
    cv::imshow("largest region", result2) ;  
    cv::imshow("maxRegion by ocmu_maxconnecteddomain", maxRegion) ;      
    cv::waitKey();  
}
```

##### Update List:

* 2015-09-11:
    + 完成初稿。

本文是开源项目 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 文档的一部分，更多的文章和完整代码请移步项目的 [Github主页][Github主页]。

转载请注明出处。

[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[Github主页]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[使用OpenCV查找二值图中最大连通区域]: http://blog.csdn.net/shaoxiaohu1/article/details/40272875




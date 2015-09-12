# (Reborn) 抠取任一连通区域的 OpenCV 实现

昨天的文档是关于抠取二值图像最大连通区域的函数 ocmu_maxconnecteddomain.cpp 的，但写完后就发现出于下面两个需求，还需要做一定的改进：
1. 有时需要的不一定是最大连通域，也可能是面积第二大的连通域，需要增加根据指定的面积大小顺序抠取连通区域；
2. 有时需要的并不一定是二值化的最大连通区域，而是连通区域的的坐标和尺寸，以此抠取原图区域。

因此，今天修改了昨天的代码，重新写了一个 ocmu_connecteddomain.cpp 函数，改动如下：
1. 定义了 `connectedDomainStruct` 结构体，用于函数返回结果，在其中还返回了指定连通区域的坐标；
2. 对连通区域面积进行了排序，添加了按照指定的面积大小次序返回结果，如果不指定，则默认为最大连通区域。

其 Demo 仍然为 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 项目 Demo_OCMU_Functions 文件夹下的 demo_ocmu_maxconnecteddomain.cpp 函数，具体使用示例如下：

```C++
    connectedDomainStruct targetStruct = ocmu_connecteddomain(binImg);
    cv::Mat_<uchar> targetRegion = targetStruct.targetRegion;
    int xBegPos = targetStruct.xBegPos;
    int yBegPos = targetStruct.yBegPos;
    int xEndPos = targetStruct.xEndPos;
    int yEndPos = targetStruct.yEndPos; 
    cv::imshow("targetRegion by ocmu_connecteddomain", targetRegion) ;  
    cv::waitKey();  
```

为了方便起见，ocmu_connecteddomain.cpp 代码陈列如下：

```C++
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
```

connectedDomainStruct 结构体的定义如下：
```C++
struct connectedDomainStruct{
     cv::Mat_<uchar> targetRegion;
     int xBegPos;
     int yBegPos;
     int xEndPos;
     int yEndPos;  
};
```

##### Update List:
* 2015-09-12:
    + 完成初稿。

本文是开源项目 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 文档的一部分，更多的文章和完整代码请移步项目的 [Github主页][Github主页]。

转载请注明出处。

[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[Github主页]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users





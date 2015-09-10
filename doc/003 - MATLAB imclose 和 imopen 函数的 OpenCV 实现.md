# MATLAB imclose 和 imopen 函数的 OpenCV 实现

今天，工作上需要用 OpenCV/C++ 实现一下 MATLAB 的 imclose 函数，也就是对图像进行闭运算。闭运算其实就是先对图像做一次膨胀再做一次腐蚀，OpenCV 的官方文档 [More Morphology Transformations][More Morphology Transformations] 有个很好的公式：

```C++
dst = close(src, element) = erode(dilate(src, element))
```

万幸的是，OpenCV 虽然没有给出闭运算的函数，但给出了膨胀和腐蚀的函数，分别是 `cv::dilate` 和 `cv::erode`。在 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 里，我在 OCMU_Functions 文件夹下添加了 ocmu_imclose.cpp 函数，给出了 MATLAB imclose 函数的 OpenCV 实现，具体 Demo 可以运行 Demo_OCMU_Functions 文件夹下的 demo_ocmu_imclose.cpp 函数。

为了方便起见，ocmu_imclose.cpp 函数内容如下：

```C++
#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat_<uchar> ocmu_imclose(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element)
{
    cv::Mat dilateImg, closeImg;
    cv::dilate(binImg, dilateImg, element);
    cv::erode(dilateImg, closeImg, element);
    return closeImg;
}
```

element 如何产生以及具体函数如何调用可以看示例 demo_ocmu_imclose.cpp，具体代码如下：

```C++
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
    cv::imshow("closeImg", closeImg);
    cv::waitKey();
}


```

在实现了闭运算后，如下所示的开运算也很容易实现：
```C++
dst = open(src, element) = dilate(erode(src, element))
```

ocmu_imopen.cpp 函数内容如下：
```C++
#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat_<uchar> ocmu_imopen(cv::Mat_<uchar> binImg, cv::Mat_<uchar> element)
{
    cv::Mat erodeImg, openImg;
    cv::erode(binImg, erodeImg, element);
    cv::dilate(erodeImg, openImg, element); 
    return openImg;
}
```
##### Update List:

* 2015-09-11:
    + 完成初稿。



[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[More Morphology Transformations]: http://docs.opencv.org/doc/tutorials/imgproc/opening_closing_hats/opening_closing_hats.html#closing




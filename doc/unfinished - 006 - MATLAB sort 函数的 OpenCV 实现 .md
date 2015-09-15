# MATLAB sort 函数的 OpenCV 实现

在 MATLAB 里，返回排序后的矩阵以及对应原矩阵的索引是在 `sort` 一个函数搞定，但在 OpenCV 中，其功能分别被分配到了 `cv::sort` 和 `cv::sortIdx` 里，`cv::sort` 负责返回排序后的矩阵，`cv::sortIdx` 负责返回对应原矩阵的索引。
还有在 MATLAB 里，1 和 2 用来分别指示是对列还是对行进行排序，'ascend' 和 'descend' 用来指示是升序还是降序。在 OpenCV 中，我们用类似于 `CV_SORT_EVERY_ROW + CV_SORT_ASCENDING` 这样的方式来一并指定对列还是对行以及升序还是降序，其指示值定义如下，所以可以组合出 4 种不同的方式：

```C++
#define CV_SORT_EVERY_ROW    0
#define CV_SORT_EVERY_COLUMN 1
#define CV_SORT_ASCENDING    0
#define CV_SORT_DESCENDING   16
```

+ CV_SORT_EVERY_ROW + CV_SORT_ASCENDING：对矩阵的**每行**按照**升序**排序；
+ CV_SORT_EVERY_ROW + CV_SORT_DESCENDING：对矩阵的**每行**按照**降序**排序；
+ CV_SORT_EVERY_COLUMN + CV_SORT_ASCENDING：对矩阵的**每列**按照**升序**排序；
+ CV_SORT_EVERY_COLUMN + CV_SORT_DESCENDING：对矩阵的**每列**按照**降序**排序；

具体代码可见 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] Demo_OpenCVFunctions 文件夹下的 demo_sort_sortIdx.cpp 函数，为了方便起见，将代码陈列如下：

```C++
#include <opencv2/opencv.hpp>
#include <iostream>

void demo_sort_sortIdx()
{
    int testArrLen = 5;
    cv::Mat_<int> testArr = cv::Mat::zeros(2, testArrLen, CV_32S);
    testArr(0,0) = 87;
    testArr(0,1) = 65;
    testArr(0,2) = 98;
    testArr(0,3) = 12;
    testArr(0,4) = 55;
    testArr(1,0) = 86;
    testArr(1,1) = 66;
    testArr(1,2) = 97;
    testArr(1,3) = 17;
    testArr(1,4) = 54;

    cv::Mat_<int> sortArr, sortIdxArr;
    cv::sort(testArr, sortArr, CV_SORT_EVERY_ROW  +  CV_SORT_ASCENDING);
    cv::sortIdx(testArr, sortIdxArr, CV_SORT_EVERY_ROW  +  CV_SORT_ASCENDING);

    std::cout<<"testArr = "<<testArr<<std::endl;
    std::cout<<"sortArr = "<<sortArr<<std::endl;
    std::cout<<"sortIdxArr = "<<sortIdxArr<<std::endl;
}
```

本文是开源项目 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 文档的一部分，更多的文章和完整代码请移步项目的 [Github主页][Github主页]。

转载请注明出处。

[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[Github主页]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users





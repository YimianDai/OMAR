今天，工作上需要用 OpenCV/C++ 实现一下 MATLAB 的 gradient 函数，我们先来看一下 gradient 是怎么工作的，代码和运行结果如下：

```MATLAB
testMat = magic(5)
[Gx, Gy] = gradient(testMat)
% testMat =
%     17    24     1     8    15
%     23     5     7    14    16
%      4     6    13    20    22
%     10    12    19    21     3
%     11    18    25     2     9
% Gx =
%     7.0000   -8.0000   -8.0000    7.0000    7.0000
%   -18.0000   -8.0000    4.5000    4.5000    2.0000
%     2.0000    4.5000    7.0000    4.5000    2.0000
%     2.0000    4.5000    4.5000   -8.0000  -18.0000
%     7.0000    7.0000   -8.0000   -8.0000    7.0000
% Gy =
%     6.0000  -19.0000    6.0000    6.0000    1.0000
%    -6.5000   -9.0000    6.0000    6.0000    3.5000
%    -6.5000    3.5000    6.0000    3.5000   -6.5000
%     3.5000    6.0000    6.0000   -9.0000   -6.5000
%     1.0000    6.0000    6.0000  -19.0000    6.0000
```
分析代码可以发现，对于 `Gx` 来说：
* 除了第一列和最后一列以外的中间部分，我们设第 `j` 列，都是 `testMat` 的第 `j+1` 列减去第 `j-1` 列然后除以 `2`；
* 对于第一列，则是第二列减去第一列的值；
* 对于最后一列，则是最后一列减去倒数第二列的值。

同理，对于 `Gy` 来说：
* 除了第一行和最后一行以外的中间部分，我们设第 `i` 行，都是 `testMat` 的第 `i+1` 行减去第 `i-1` 行然后除以 `2`；
* 对于第一行，则是第二行减去第一行的值；
* 对于最后一行，则是最后一行减去倒数第二行的值。

在 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 里，我在 OCMU_Functions 文件夹下添加了 ocmu_gradient.cpp 函数，给出了 MATLAB gradient 函数的 OpenCV 实现，具体 Demo 可以运行 Demo_OCMU_Functions 文件夹下的 
demo_ocmu_gradient.cpp 函数。

为了方便起见，ocmu_gradient.cpp 函数内容如下：

```C++
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
```




[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users




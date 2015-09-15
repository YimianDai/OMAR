# MATLAB Logical Indexing 的 OpenCV 实现 

这篇文章主要是 stackoverflow 上的一个问题 [How To Index And Modify An OpenCV Matrix][How To Index And Modify An OpenCV Matrix] 的翻译。在 MATLAB 里，Logical Indexing 是非常常见的一种用法，具体示例如下：

```MATLAB
A = [1;2;3;1;2;3;1;2;3];
A(A==1) = 0
% Resulting in:
% [0;2;3;0;2;3;0;2;3]
```

在 OpenCV 里，Logical Indexing 的实现并不像 MATLAB 那样简洁，但也相差不大。`setTo()` 函数可以接受 `cv::Mat` 的逻辑运算，比如 `==` 和 `!=`，的结果作为参数，具体代码可见 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] Demo_OpenCVFunctions 文件夹下的 demo_setTo.cpp 函数，为了方便起见，将代码陈列如下：

```C++
#include <opencv2/opencv.hpp>
#include <iostream>

void demo_setTo()
{
    uchar data[] = {1,2,3,1,2,3,1,2,3};
    //cv::Mat A(9, 1, CV_8UC1, data); // 1, 9 is also OK
    cv::Mat A(1, 9, CV_8UC1, data);
    std::cout<<"Before: A = "<<A<<std::endl;
    A.setTo(0, A == 1);
    std::cout<<"After: A = "<<A<<std::endl;
}
```

在[How To Index And Modify An OpenCV Matrix][How To Index And Modify An OpenCV Matrix]中，它是写成 `A = A.setTo(0, A == 1);` 这样的，但我觉得直接 `A.setTo(0, A == 1);` 就行了。

本文是开源项目 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 文档的一部分，更多的文章和完整代码请移步项目的 [Github主页][Github主页]。

转载请注明出处。

[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[Github主页]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[How To Index And Modify An OpenCV Matrix]: http://stackoverflow.com/questions/18233691/how-to-index-and-modify-an-opencv-matrix





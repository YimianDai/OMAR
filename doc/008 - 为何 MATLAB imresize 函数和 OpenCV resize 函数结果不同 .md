# 为何 MATLAB imresize 函数和 OpenCV resize 函数结果不同 

为何 MATLAB imresize 函数和 OpenCV resize 函数结果不同？今年 4 月，我在依照 MATLAB 代码自己写一个卷积神经网络 C++ 实现的过程中，就发现了这个问题，不过那时问题不是太大，所以也没有给出太多关注。今天在 stackoverflow 上正好看到了一个相关问题 [why OpenCV cv2.resize gives different answer than MATLAB imresize?][why OpenCV cv2.resize gives different answer than MATLAB imresize?]，解答了我心中的疑惑。这篇的文章主要内容是将这个 stackoverflow 问题做了注解，并将部分代码由 Python 翻译成 C++。

首先我们可以看到，在变大的时候，MATLAB 和 OpenCV 有一样的结果：

```MATLAB
x = imresize([1,2;3,4],[4,4],'bilinear')
% x =
%     1.0000    1.2500    1.7500    2.0000
%     1.5000    1.7500    2.2500    2.5000
%     2.5000    2.7500    3.2500    3.5000
%     3.0000    3.2500    3.7500    4.0000
```

```C++
    double data[] = {1, 2, 3, 4};
    cv::Mat A(2, 2, CV_64FC1, data);
    std::cout<<"Before: A = "<<A<<std::endl;
    cv::resize(A, A, cv::Size(4, 4), cv::INTER_LINEAR);
    std::cout<<"resize bigger: A = "<<A<<std::endl;
    //    [1, 1.25, 1.75, 2;
    //    1.5, 1.75, 2.25, 2.5;
    //    2.5, 2.75, 3.25, 3.5;
    //    3, 3.25, 3.75, 4]
```

但是，在把矩阵缩小的时候，却出现了结果不一样：

```MATLAB
imresize(x,[2,2],'bilinear')
% ans =
%    1.5625    2.1875
%    2.8125    3.4375
```

```C++
    cv::resize(A, A, cv::Size(2, 2), cv::INTER_LINEAR);
    std::cout<<"resize smaller: A = "<<A<<std::endl;
    //    [1.375, 2.125;
    //    2.875, 3.625]
```

这是为什么呢？原因在于 MATLAB 的 `imresize` 函数默认是开启了 **anti-aliasing**，将其关闭，结果就跟 C++ 一样了：

```MATLAB
imresize(x,[2,2],'bilinear','AntiAliasing',false)
% ans =
%    1.3750    2.1250
%    2.8750    3.6250
```

那么问题来了，怎么让 OpenCV 做到 MATLAB imresize 函数的 anti-aliasing 功能呢？这个问题，留待日后解决。本文具体代码可见 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] Demo_OpenCVFunctions 文件夹下的 demo_resize.cpp 函数，为了方便起见，将代码陈列如下：

```C++
#include <opencv2/opencv.hpp>
#include <iostream>

void demo_resize()
{
    double data[] = {1, 2, 3, 4};
    cv::Mat A(2, 2, CV_64FC1, data);
    std::cout<<"Before: A = "<<A<<std::endl;
    cv::resize(A, A, cv::Size(4, 4), cv::INTER_LINEAR);
    std::cout<<"resize bigger: A = "<<A<<std::endl;
    cv::resize(A, A, cv::Size(2, 2), cv::INTER_LINEAR);
    std::cout<<"resize smaller: A = "<<A<<std::endl;
}
```

本文是开源项目 [OpenCV-and-CPP-for-MATLAB-Users][OpenCV-and-CPP-for-MATLAB-Users] 文档的一部分，更多的文章和完整代码请移步项目的 [Github主页][Github主页]。

转载请注明出处。

[OpenCV-and-CPP-for-MATLAB-Users]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[Github主页]: https://github.com/YimianDai/OpenCV-and-CPP-for-MATLAB-Users
[How To Index And Modify An OpenCV Matrix]: http://stackoverflow.com/questions/18233691/how-to-index-and-modify-an-opencv-matrix
[why OpenCV cv2.resize gives different answer than MATLAB imresize?]: http://stackoverflow.com/questions/21997094/why-opencv-cv2-resize-gives-different-answer-than-matlab-imresize





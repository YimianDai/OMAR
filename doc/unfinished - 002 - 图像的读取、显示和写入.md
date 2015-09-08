# 图像的读取、显示和写入

## 正文

在《001 - Visual Studio 配置 OpenCV》中，其实已经给出了图像读取和显示的例子了，这一章中我们来更加深入和详细地了解下 OpenCV 中图像读写的相关内容。

### 图像读取

OpenCV 的 `cv::imread` 基本支持所有的主流格式，具体的可以看《The OpenCV Reference Manual》中给出的列表。《The OpenCV Reference Manual》里给出了 3 种 C/C++ 读取的方式，分别如下：

```C++
C++: Mat imread(const string& ﬁlename, int ﬂags=1 )
C: IplImage* cvLoadImage(const char* ﬁlename, int iscolor=CV_LOAD_IMAGE_COLOR )
C: CvMat* cvLoadImageM(const char* ﬁlename, int iscolor=CV_LOAD_IMAGE_COLOR )
```

再来看下参数：

* ﬁlename – （包含路径的）文件名，对于 C++ 用法要求是 `std::string` 对象，对于 C 用法则是 char 数组.
* ﬂags – 用来指示读入图像的颜色类型，之前我就因为没有强制将图像转化为灰度图像这一个疏漏耗费了10天时间来找项目程序的问题所在：
	+ CV_LOAD_IMAGE_ANYDEPTH - If set, return 16-bit/32-bit image when the input has
the corresponding depth, otherwise convert it to 8-bit.
	+ CV_LOAD_IMAGE_COLOR - 如果设置了，永远返回彩色图像。
	+ CV_LOAD_IMAGE_GRAYSCALE - 如果设置了，永远返回灰度图像。
	– >0 Return a 3-channel color image. 其实你会发现，CV_LOAD_IMAGE_COLOR 就是一个 int 类型的 1.
	– =0 Return a grayscale image，CV_LOAD_IMAGE_GRAYSCALE 就是 0.
	– <0 Return the loaded image as is (with alpha channel).

需要注意的是，如果读取的文件不存在、不具有授权、格式不被支持等问题存在，`cv::imread` 会返回一个空矩阵(`cv::Mat::data == NULL`)


### 图像显示

```C++
C++: void imshow(const string& winname, InputArray mat)
C: void cvShowImage(const char* name, const CvArr* image)
```

我猜 `CvArr` 是 `IplImage` 和 `CvMat` 的父类，所以能用 `cvShowImage` 显示图像，具体看下面的示例。

显示完图像后，IplImage 和 CvMat 还要记得释放内存。

### 图像写入




## 代码示例
代码示例如下，也可以访问我的 Github 项目，文件 imagedemo_002.cpp

```C++

```

## Update List

* 2015-09-08: 
	+ 完成了文章的主体框架，还欠缺图像写入部分。
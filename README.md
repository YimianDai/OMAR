#### Introduction 

代码注释分为两种，`//` 用于说明代码的功能，`/* */` 则是一个小 demo 的标题。

主要是我遇到什么问题了，有些是按照功能划分的，有些是根据每个类型划分的，彼此之间可能会有很多重合和冗余。

#### 项目架构
* data: Directory storing the input data.
* images: Directory storing the input images.
* outputs: Directory storing the output results.
* src
	+ Demo_Class: Demo for the attributes and functions of classes of OpenCV and C++
    	- matdemo.cpp: Demo for the attributes and functions of `cv::Mat`;
    	- stringdemo.cpp: Demo for the attributes and functions of `std::string`;
  	+ Demo_Input_Output: Demos for file input and output operations
    	- imagedemo.cpp: Demo for operations of images;
    	- matdemo.cpp: Demo for operations of MATLAB .mat files;
    + Headers: header files
    + globalparameters.cpp: a file for setting global parameters.
    + Source.cpp: Main program.
* README.md

#### Update List: 
* 2015-09-01: 
  	+ 初步建立了项目框架；
  	+ 添加了把 `std::string` 对象变成 `char` 数组的示例;
  	+ 添加了验证把 `cv::Mat_<double>` 赋值给 `cv::Mat_<float>` 是否会有大问题的示例。结论不会，只是精度有损失。

* 2015-09-04:
  	+ 添加了 `imread` 和 `imwrite` 的示例；
  	+ 添加了通过 YML 文件读取 MATLAB .mat 数据的示例；
  	+ 添加了检查图像是否被正确读取的示例；


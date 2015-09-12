#include <opencv2/opencv.hpp>
#include <iostream>
#include "..\Headers\syntax_demo.h"

void demo_syntax() {
	returnStruct haha = demo_returnstruct();
	std::cout<<"haha.x = "<<haha.x<<std::endl;
	std::cout<<"haha.y = "<<haha.y<<std::endl;

	int defaultSum = demo_defaultvalue(3);
	std::cout<<"defaultSum = "<<defaultSum<<std::endl;
}
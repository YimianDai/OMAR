#include <opencv2/opencv.hpp>
#include <iostream>
#include "Headers\class_demo.h"
#include "Headers\input_output_demo.h"
#include "Headers\ocmu_function_demo.h"
#include "Headers\ocmu_functions.h"

// Please change the project path in your computer here to run successfully
extern std::string projectPath = \
	"D:\\MyNutCloud\\GitHub\\OpenCV-and-CPP-for-MATLAB-Users\\";

int main(int argc, char **argv)
{ 

	//// Transfer std::string object into char array
	//const char* imgPathCharArr = imgPathStr.c_str();
	//std::cout<<"imgPathCharArr = "<<imgPathCharArr<<std::endl;

	/*                                             */
	/*                  Demo_Class                 */
	/*                                             */

	/*Demos for Attributes and Functions of Classes*/
	//stringdemo();

	/*Demos for Attributes and Functions of Classes*/
	//cvmatdemo();

	/*                                                    */
	/*                  Demo_Input_Output                 */
	/*                                                    */
	
	/*Demo for operations of images*/
	//imagedemo_002();

	/*Demo for operations of MATLAB .mat files*/
	//matlabmatdemo();

	//demo_ocmu_gradient();
	demo_ocmu_imclose();

	std::system("PAUSE");
	return 0;
}
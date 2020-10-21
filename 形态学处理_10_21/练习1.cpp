#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\硬币.jpg");
	cv::Mat binary, ErosionImage, DilationImage,open,close;
	cv::Mat element;
	int Kernelsize = 3;

	threshold(srcMat, binary, 100, 255, THRESH_BINARY);
	element = getStructuringElement(MORPH_RECT,Size(Kernelsize, Kernelsize));

	erode(binary, ErosionImage, element); //腐蚀
	dilate(binary, DilationImage, element); //膨胀
	morphologyEx(binary, open, 2, element); //开运算
	morphologyEx(binary, close, 3, element); //闭运算


	imshow("原图", srcMat);
	imshow("二值化结果", binary);
	imshow("腐蚀效果图", ErosionImage);
	imshow("膨胀效果图", DilationImage);
	imshow("开运算", open);
	imshow("闭运算", close);
	waitKey(0);
	
}
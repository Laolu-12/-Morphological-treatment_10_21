#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\焊点.jpg", 0); //转成灰度图
	cv::Mat dstMat, binary,OpenImg,CloseImg,result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // 结构算子
	int Kernelsize = 52;

	dstMat = 255 - srcMat;
	threshold(dstMat, binary, 100, 255, THRESH_OTSU);
	imshow("二值化结果", binary);
	
	element = getStructuringElement(MORPH_ELLIPSE, Size(Kernelsize, Kernelsize));

	morphologyEx(binary, CloseImg, 3, element); //闭运算
	imshow("闭运算", CloseImg);

	morphologyEx(binary, OpenImg, 2, element); //开运算
	imshow("开运算", OpenImg);
	result = binary - OpenImg;
	imshow("结果",result);

	connectedComponentsWithStats(CloseImg, labels, stats, centroids, 8, CV_32S);

	cout << stats << endl;


	waitKey(0);

}
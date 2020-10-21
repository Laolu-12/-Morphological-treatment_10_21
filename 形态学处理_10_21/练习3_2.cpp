#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\焊点.jpg", 0); //转成灰度图
	cv::Mat dstMat, binary, OpenImg, CloseImg, result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // 结构算子
	int Kernelsize = 20;
	int num;

	
	threshold(srcMat, binary, 100, 255, THRESH_OTSU); //使用大津法进行二值化
	imshow("二值化结果", binary);

	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize));

	//实现想法是，使用大小合适的矩形算子对二值化图像进行闭运算处理，使非圆焊点的黑色方形区域膨胀成为白色背景，然后将图片反置一下，使圆焊点变成白色，再用连通域标记函数计算焊点数量

	morphologyEx(binary, CloseImg, 3, element); //闭运算
	imshow("闭运算", CloseImg);

	dstMat = 255 - CloseImg;//将处理后的图像的通道值反一下
	imshow("反置后图像", dstMat);

	num = connectedComponentsWithStats(dstMat, labels, stats, centroids, 8, CV_32S);

	cout <<"焊点个数为："<<num - 1 << endl; //减去背景数量


	waitKey(0);

}
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\回形针.jpg", 0); //转成灰度图
	cv::Mat dstMat, binary, OpenImg, CloseImg, result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // 结构算子
	int Kernelsize = 5;
	int num;


	threshold(srcMat, binary, 100, 255, THRESH_OTSU); //使用大津法进行二值化
	imshow("二值化结果", binary);

	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize));

	dstMat = 255 - binary;
	imshow("反置后图像", dstMat);

	num = connectedComponentsWithStats(dstMat, labels, stats, centroids, 8, CV_32S);

	cout << "个数为：" << num - 1 << endl; //减去背景数量





	waitKey(0);
}
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\硬币.jpg", 0); //需先转成单通道灰度图才能用连通域标记函数
	cv::Mat binary, CloseImg, labels, stats, centroids;
	cv::Mat element;
	Point Start, End;
	int Count=0;
	int Kernelsize = 3;


	threshold(srcMat, binary, 100, 255, THRESH_BINARY); //二值化
	imshow("二值化结果", binary);
	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize)); //结构算子

	morphologyEx(binary, CloseImg, 3, element); //闭运算
	imshow("闭运算",CloseImg);

	connectedComponentsWithStats(CloseImg, labels, stats, centroids, 8, CV_32S); //连通域标记
	for (int a = 0; a < stats.rows; a++)
	{

		long* data = stats.ptr<long>(a);
		if (data[4] < 10000)//面积太大的连通域肯定是背景
		{
			Count++;
			Start.x = data[0]; //起点
			Start.y = data[1];
			End.x = Start.x + data[2]; //起点横坐标+宽度=终点横坐标
			End.y = Start.y + data[3]; //起点纵坐标+高度=终点纵坐标
			rectangle(srcMat, Start, End, CV_RGB(255, 255, 255), 3); //绘制外接四边形

		}			
	}
	cout << "硬币个数为：" << Count << endl;
	imshow("原图", srcMat);
	



	waitKey(0);
}
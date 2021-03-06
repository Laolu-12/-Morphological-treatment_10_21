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
	int num=0;


	threshold(srcMat, binary, 100, 255, THRESH_OTSU); //使用大津法进行二值化
	imshow("二值化结果", binary);

	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize));

	dstMat = 255 - binary;
	imshow("反置后图像", dstMat);

	connectedComponentsWithStats(dstMat, labels, stats, centroids, 8, CV_32S);
	for (int a = 0; a < stats.rows; a++)
	{
		long *data = stats.ptr<long>(a);
		if (data[4] > 4000 && data[4] < 10000) //观察stats状态后发现面积在这个范围内，属于回形针
			num++;
	}

	cout << "回形针个数为：" << num  << endl; //减去背景数量
	cout << stats << endl;





	waitKey(0);
}
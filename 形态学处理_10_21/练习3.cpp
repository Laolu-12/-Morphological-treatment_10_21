#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\����.jpg", 0); //ת�ɻҶ�ͼ
	cv::Mat dstMat, binary,OpenImg,CloseImg,result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // �ṹ����
	int Kernelsize = 52;

	dstMat = 255 - srcMat;
	threshold(dstMat, binary, 100, 255, THRESH_OTSU);
	imshow("��ֵ�����", binary);
	
	element = getStructuringElement(MORPH_ELLIPSE, Size(Kernelsize, Kernelsize));

	morphologyEx(binary, CloseImg, 3, element); //������
	imshow("������", CloseImg);

	morphologyEx(binary, OpenImg, 2, element); //������
	imshow("������", OpenImg);
	result = binary - OpenImg;
	imshow("���",result);

	connectedComponentsWithStats(CloseImg, labels, stats, centroids, 8, CV_32S);

	cout << stats << endl;


	waitKey(0);

}
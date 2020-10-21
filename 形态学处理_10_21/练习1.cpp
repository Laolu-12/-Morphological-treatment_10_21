#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\Ӳ��.jpg");
	cv::Mat binary, ErosionImage, DilationImage,open,close;
	cv::Mat element;
	int Kernelsize = 3;

	threshold(srcMat, binary, 100, 255, THRESH_BINARY);
	element = getStructuringElement(MORPH_RECT,Size(Kernelsize, Kernelsize));

	erode(binary, ErosionImage, element); //��ʴ
	dilate(binary, DilationImage, element); //����
	morphologyEx(binary, open, 2, element); //������
	morphologyEx(binary, close, 3, element); //������


	imshow("ԭͼ", srcMat);
	imshow("��ֵ�����", binary);
	imshow("��ʴЧ��ͼ", ErosionImage);
	imshow("����Ч��ͼ", DilationImage);
	imshow("������", open);
	imshow("������", close);
	waitKey(0);
	
}
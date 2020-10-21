#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\����.jpg", 0); //ת�ɻҶ�ͼ
	cv::Mat dstMat, binary, OpenImg, CloseImg, result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // �ṹ����
	int Kernelsize = 20;
	int num;

	
	threshold(srcMat, binary, 100, 255, THRESH_OTSU); //ʹ�ô�򷨽��ж�ֵ��
	imshow("��ֵ�����", binary);

	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize));

	//ʵ���뷨�ǣ�ʹ�ô�С���ʵľ������ӶԶ�ֵ��ͼ����б����㴦��ʹ��Բ����ĺ�ɫ�����������ͳ�Ϊ��ɫ������Ȼ��ͼƬ����һ�£�ʹԲ�����ɰ�ɫ��������ͨ���Ǻ������㺸������

	morphologyEx(binary, CloseImg, 3, element); //������
	imshow("������", CloseImg);

	dstMat = 255 - CloseImg;//��������ͼ���ͨ��ֵ��һ��
	imshow("���ú�ͼ��", dstMat);

	num = connectedComponentsWithStats(dstMat, labels, stats, centroids, 8, CV_32S);

	cout <<"�������Ϊ��"<<num - 1 << endl; //��ȥ��������


	waitKey(0);

}
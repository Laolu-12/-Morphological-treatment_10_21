#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\Ӳ��.jpg", 0); //����ת�ɵ�ͨ���Ҷ�ͼ��������ͨ���Ǻ���
	cv::Mat binary, CloseImg, labels, stats, centroids;
	cv::Mat element;
	Point Start, End;
	int Count=0;
	int Kernelsize = 3;


	threshold(srcMat, binary, 100, 255, THRESH_BINARY); //��ֵ��
	imshow("��ֵ�����", binary);
	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize)); //�ṹ����

	morphologyEx(binary, CloseImg, 3, element); //������
	imshow("������",CloseImg);

	connectedComponentsWithStats(CloseImg, labels, stats, centroids, 8, CV_32S); //��ͨ����
	for (int a = 0; a < stats.rows; a++)
	{

		long* data = stats.ptr<long>(a);
		if (data[4] < 10000)//���̫�����ͨ��϶��Ǳ���
		{
			Count++;
			Start.x = data[0]; //���
			Start.y = data[1];
			End.x = Start.x + data[2]; //��������+���=�յ������
			End.y = Start.y + data[3]; //���������+�߶�=�յ�������
			rectangle(srcMat, Start, End, CV_RGB(255, 255, 255), 3); //��������ı���

		}			
	}
	cout << "Ӳ�Ҹ���Ϊ��" << Count << endl;
	imshow("ԭͼ", srcMat);
	



	waitKey(0);
}
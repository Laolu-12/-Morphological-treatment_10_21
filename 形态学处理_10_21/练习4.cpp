#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\������.jpg", 0); //ת�ɻҶ�ͼ
	cv::Mat dstMat, binary, OpenImg, CloseImg, result;
	cv::Mat labels, stats, centroids;
	cv::Mat element; // �ṹ����
	int Kernelsize = 5;
	int num=0;


	threshold(srcMat, binary, 100, 255, THRESH_OTSU); //ʹ�ô�򷨽��ж�ֵ��
	imshow("��ֵ�����", binary);

	element = getStructuringElement(MORPH_RECT, Size(Kernelsize, Kernelsize));

	dstMat = 255 - binary;
	imshow("���ú�ͼ��", dstMat);

	connectedComponentsWithStats(dstMat, labels, stats, centroids, 8, CV_32S);
	for (int a = 0; a < stats.rows; a++)
	{
		long *data = stats.ptr<long>(a);
		if (data[4] > 4000 && data[4] < 10000) //�۲�stats״̬��������������Χ�ڣ����ڻ�����
			num++;
	}

	cout << "���������Ϊ��" << num  << endl; //��ȥ��������
	cout << stats << endl;





	waitKey(0);
}
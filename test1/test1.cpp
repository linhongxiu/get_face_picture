// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//�ɼ��Լ�������������Ԥ�����Ա�ѵ������ģ��

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <opencv2\videoio.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture capture(0);
	Mat frame;
	string filename;
	char key;
	int i = 11;

	if (!capture.isOpened())
	{
		cout << "����ͷ��ʧ�ܣ�" << endl;
		return -1;
	}
	while (1)
	{
		key = waitKey(100);         //�ȴ�100ms
		capture >> frame;
		imshow("frame", frame);
		filename = format("D:\\OpenCV\\face_data\\picture%d.jpg", i);

		switch (key)
		{
		case'p':           //P����������
			i++;
			imwrite(filename, frame);
			imshow("photo", frame);
			waitKey(500);                   //�ȴ�500ms
			destroyWindow("photo");
			break;
		default:         //����������˳�����
			break;
		}
	}
    return 0;
}


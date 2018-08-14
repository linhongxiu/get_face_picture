// test1.cpp : 定义控制台应用程序的入口点。
//采集自己的人脸数据来预处理并以便训练人脸模型

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
		cout << "摄像头打开失败！" << endl;
		return -1;
	}
	while (1)
	{
		key = waitKey(100);         //等待100ms
		capture >> frame;
		imshow("frame", frame);
		filename = format("D:\\OpenCV\\face_data\\picture%d.jpg", i);

		switch (key)
		{
		case'p':           //P键进行拍照
			i++;
			imwrite(filename, frame);
			imshow("photo", frame);
			waitKey(500);                   //等待500ms
			destroyWindow("photo");
			break;
		default:         //其它任意键退出程序
			break;
		}
	}
    return 0;
}


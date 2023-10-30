// StringPainting_Demo_v0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 第一次运行时，请先取消（1）行 的注释，注释（2）行，运行，在选定文件夹生成采样图片
// 第一次运行完后，将宏 TOTAL_FRAME_COUNT 改为第一次运行时显示的总帧数
// 第一次运行完后，请注释（1）行，取消（2）行注释

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Img.h"

#define TOTAL_FRAME_COUNT 1306
#define FLAG_PRINTCHAR_TYPE 1

int main()
{
	std::cout << "Hello, world from OpenCV" << std::endl;
	Img p1;

	//例1：鸡哥
	/*
	//p1.getFrame("C:/Users/zhr20/Pictures/testPictures/ikun.mp4", "C:/Users/zhr20/Pictures/testPictures/ikun", "ikun", "jpg"); //（1）

	Mat test = cv::imread("C:/Users/zhr20/Pictures/testPictures/P5.jpg");
	p1.zip_equal(test, 8);
	p1.outputStringPainting(test, 24);
	waitKey(500);
	system("cls");

	p1.picturesToStringPaintings("C:/Users/zhr20/Pictures/testPictures/ikun", "ikun", "jpg", TOTAL_FRAME_COUNT); //（2）
	waitKey(0);
	*/

	//例2：香蕉君
	
	//p1.getFrame("C:/Users/zhr20/Pictures/testPictures/banana.mp4", "C:/Users/zhr20/Pictures/testPictures/banana", "banana", "jpg"); //（1）
	p1.picturesToStringPaintings("C:/Users/zhr20/Pictures/testPictures/banana", "banana", "jpg", TOTAL_FRAME_COUNT, FLAG_PRINTCHAR_TYPE); //（2）
	waitKey(0);
	
	
	//例3：Bad Apple
	//p1.getFrame("C:/Users/zhr20/Pictures/testPictures/BadApple.mp4", "C:/Users/zhr20/Pictures/testPictures/BadApple", "BadApple", "jpg"); //（1）
	//p1.picturesToStringPaintings("C:/Users/zhr20/Pictures/testPictures/BadApple", "BadApple", "jpg", TOTAL_FRAME_COUNT, FLAG_PRINTCHAR_TYPE); //（2）
	//waitKey(0);


	
	return 0;
}


#include "Img.h"
#include <cmath>

void Img::outputStringPainting(Mat& image, int percison)
{
	int height = image.cols;
	int width = image.rows;
	int pv;

	Mat gray, gray_T;
	std::vector<Mat> planes;
	cvtColor(image, gray_T, COLOR_BGR2GRAY);
	threshold(gray_T, gray, 128, 255, THRESH_TOZERO);
	split(gray, planes);

	for (int row = 0; row < width; row++) {
		uchar* current_row = planes[0].ptr<uchar>(row);
		for (int col = 0; col < height; col++) {
			pv = *current_row++;
			printchar(pv, percison);
		}
		std::cout << "\n";
	}
}

void Img::printchar(int pv, int k)
{
	if (pv < k) {
		std::cout << GRAYLEVEL7;
	}
	else if (pv < k * 2) {
		std::cout << GRAYLEVEL6;
	}
	else if (pv < k * 3) {
		std::cout << GRAYLEVEL5;
	}
	else if (pv < k * 4) {
		std::cout << GRAYLEVEL4;
	}
	else if (pv < k * 5) {
		std::cout << GRAYLEVEL3;
	}
	else if (pv < k * 6) {
		std::cout << GRAYLEVEL2;
	}
	else if (pv < k * 7) {
		std::cout << GRAYLEVEL1;
	}
	else {
		std::cout << GRAYLEVEL0;
	}
}

void Img::zip(Mat& image, int a, int b)
{
	//照片result1.jpg改变像素（尺寸大小）
	Size srcSize = Size(a, b);  //填入任意指定尺寸
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	imshow("压缩图", image);
	//imwrite("result2.jpg", image);  //保存图片
	//waitKey(0);
}

void Img::zip_equal(Mat& image, int n, int flag_print)
{
	int height = image.cols / n;
	int width = image.rows / n;
	//照片result1.jpg改变像素（尺寸大小）
	Size srcSize = Size(height, width);  //填入任意指定尺寸
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	if (flag_print != 0) {
		imshow("压缩图", image);
	}
	
}

#define waitSecond 100
#define zipTimes 15
#define printPercison 30
void Img::ikun()
{
	Mat test01 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/1.png");
	zip_equal(test01, zipTimes);
	outputStringPainting(test01, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test02 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/2.png");
	zip_equal(test02, zipTimes);
	outputStringPainting(test02, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test03 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/3.png");
	zip_equal(test03, zipTimes);
	outputStringPainting(test03, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test04 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/4.png");
	zip_equal(test04, zipTimes);
	outputStringPainting(test04, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test05 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/5.png");
	zip_equal(test05, zipTimes);
	outputStringPainting(test05, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test06 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/6.png");
	zip_equal(test06, zipTimes);
	outputStringPainting(test06, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test07 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/7.png");
	zip_equal(test07, zipTimes);
	outputStringPainting(test07, printPercison);
	waitKey(waitSecond);
	system("cls");

	Mat test08 = cv::imread("C:/Users/zhr20/Pictures/testPictures/ikun/8.png");
	zip_equal(test08, zipTimes);
	outputStringPainting(test08, printPercison);
	waitKey(waitSecond);
	system("cls");

}

void Img::ikun_02()
{
	char i ='1';
	std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //初始化string类型，并具体赋值
	str = str + i + ".png";

	const char* constc = str.c_str();                 //string类型转const char*类型

	Mat test01 = cv::imread(constc);
	zip_equal(test01, zipTimes);
	imshow("str", test01);

}

void Img::ikun_03()
{
	Mat *pikun;
	std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //初始化string类型，并具体赋值
	std::string inputStr;

	for (char i = '1'; i < '7'; i++) {
		pikun = new Mat;
		inputStr = str + i + ".png";
		*pikun = cv::imread(inputStr);
		zip_equal(*pikun, zipTimes);
		outputStringPainting(*pikun, printPercison);
		waitKey(waitSecond);
		system("cls");
	}

	for (int j = 0; j < 10; j++) {
		for (char i = '4'; i < '7'; i++) {
			pikun = new Mat;
			inputStr = str + i + ".png";
			*pikun = cv::imread(inputStr);
			zip_equal(*pikun, zipTimes);
			outputStringPainting(*pikun, printPercison);
			waitKey(waitSecond);
			system("cls");
		}
	}
}

void Img::ikun_04()
{
	Mat* pikun;
	//std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //初始化string类型，并具体赋值
	std::string str = "C:/Users/zhr20/Desktop/ikun/ikun";
	//std::string inputStr;

	for (int i = 1; i < 177; i++) {
		pikun = new Mat;
		//inputStr << i << ".png";
		*pikun = cv::imread(str + std::to_string(i) + ".jpg");
		zip_equal(*pikun, zipTimes);
		outputStringPainting(*pikun, printPercison);
		waitKey(waitSecond);
		system("cls");
		delete pikun;
	}

	/*for (int j = 0; j < 10; j++) {
		for (char i = '4'; i < '7'; i++) {
			pikun = new Mat;
			inputStr = str + i + ".png";
			*pikun = cv::imread(inputStr);
			zip_equal(*pikun, zipTimes);
			outputStringPainting(*pikun, printPercison);
			waitKey(waitSecond);
			system("cls");
		}
	}*/
}


// 描述：将视频帧转成图片输出
void Img::getFrame()
{
	// 获取视频文件
	VideoCapture cap("C:/Users/zhr20/Downloads/ikun.mp4");
	if (!cap.isOpened())//如果视频不能正常打开则返回
		return;


	// 获取视频总帧数
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	std::cout << "total frames: " << totalFrameNumber << std::endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 0;

	while (flags) {
		// 读取视频每一帧
		cap.read(frame);

		std::stringstream str;
		str << "ikun" << currentFrame << ".jpg";
		std::cout << "正在处理第" << currentFrame << "帧" << std::endl;
		printf("\n");

		// 设置每30帧获取一次帧
		if (currentFrame % 30 == 0) {
			// 将帧转成图片输出
			imwrite("C:/Users/zhr20/Desktop/ikun/" + str.str(), frame);
		}
		// 结束条件
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	system("pause");
}

#define SAMPLE_INTERVAL 10 //视频取样间隔
// 描述：将视频帧转成图片输出
void Img::getFrame_01()
{
	// 获取视频文件
	VideoCapture cap("C:/Users/zhr20/Downloads/ikun.mp4");
	if (!cap.isOpened()) {
		//如果视频不能正常打开则返回
		std::cout << "Error : Fail to open the video" << std::endl;
		return;
	}


	// 获取视频总帧数
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	std::cout << "total frames: " << totalFrameNumber << std::endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 0;
	long outputFrame = 0;

	while (flags) {
		// 读取视频每一帧
		cap.read(frame);

		std::stringstream str;
		str << "ikun" << outputFrame << ".jpg";
		std::cout << "正在处理第" << currentFrame << "帧" << std::endl;
		printf("\n");

		// 设置每 SAMPLE_INTERVAL 帧获取一次帧
		if (currentFrame % SAMPLE_INTERVAL == 0) {
			// 将帧转成图片输出
			imwrite("C:/Users/zhr20/Desktop/ikun/" + str.str(), frame);
			std::cout << ">>输出为第" << outputFrame << "帧" << std::endl;
			printf("\n");
			outputFrame++;
		}
		// 结束条件
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	system("pause");
}
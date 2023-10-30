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
	//��Ƭresult1.jpg�ı����أ��ߴ��С��
	Size srcSize = Size(a, b);  //��������ָ���ߴ�
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	imshow("ѹ��ͼ", image);
	//imwrite("result2.jpg", image);  //����ͼƬ
	//waitKey(0);
}

void Img::zip_equal(Mat& image, int n, int flag_print)
{
	int height = image.cols / n;
	int width = image.rows / n;
	//��Ƭresult1.jpg�ı����أ��ߴ��С��
	Size srcSize = Size(height, width);  //��������ָ���ߴ�
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	if (flag_print != 0) {
		imshow("ѹ��ͼ", image);
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
	std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //��ʼ��string���ͣ������帳ֵ
	str = str + i + ".png";

	const char* constc = str.c_str();                 //string����תconst char*����

	Mat test01 = cv::imread(constc);
	zip_equal(test01, zipTimes);
	imshow("str", test01);

}

void Img::ikun_03()
{
	Mat *pikun;
	std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //��ʼ��string���ͣ������帳ֵ
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
	//std::string str = "C:/Users/zhr20/Pictures/testPictures/ikun/";     //��ʼ��string���ͣ������帳ֵ
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


// ����������Ƶ֡ת��ͼƬ���
void Img::getFrame()
{
	// ��ȡ��Ƶ�ļ�
	VideoCapture cap("C:/Users/zhr20/Downloads/ikun.mp4");
	if (!cap.isOpened())//�����Ƶ�����������򷵻�
		return;


	// ��ȡ��Ƶ��֡��
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	std::cout << "total frames: " << totalFrameNumber << std::endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 0;

	while (flags) {
		// ��ȡ��Ƶÿһ֡
		cap.read(frame);

		std::stringstream str;
		str << "ikun" << currentFrame << ".jpg";
		std::cout << "���ڴ����" << currentFrame << "֡" << std::endl;
		printf("\n");

		// ����ÿ30֡��ȡһ��֡
		if (currentFrame % 30 == 0) {
			// ��֡ת��ͼƬ���
			imwrite("C:/Users/zhr20/Desktop/ikun/" + str.str(), frame);
		}
		// ��������
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	system("pause");
}

#define SAMPLE_INTERVAL 10 //��Ƶȡ�����
// ����������Ƶ֡ת��ͼƬ���
void Img::getFrame_01()
{
	// ��ȡ��Ƶ�ļ�
	VideoCapture cap("C:/Users/zhr20/Downloads/ikun.mp4");
	if (!cap.isOpened()) {
		//�����Ƶ�����������򷵻�
		std::cout << "Error : Fail to open the video" << std::endl;
		return;
	}


	// ��ȡ��Ƶ��֡��
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	std::cout << "total frames: " << totalFrameNumber << std::endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 0;
	long outputFrame = 0;

	while (flags) {
		// ��ȡ��Ƶÿһ֡
		cap.read(frame);

		std::stringstream str;
		str << "ikun" << outputFrame << ".jpg";
		std::cout << "���ڴ����" << currentFrame << "֡" << std::endl;
		printf("\n");

		// ����ÿ SAMPLE_INTERVAL ֡��ȡһ��֡
		if (currentFrame % SAMPLE_INTERVAL == 0) {
			// ��֡ת��ͼƬ���
			imwrite("C:/Users/zhr20/Desktop/ikun/" + str.str(), frame);
			std::cout << ">>���Ϊ��" << outputFrame << "֡" << std::endl;
			printf("\n");
			outputFrame++;
		}
		// ��������
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	system("pause");
}
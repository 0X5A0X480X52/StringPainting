#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

// 以下字符用于表示不同灰度的像素>>  ||ii!!II][##@@
#define GRAYLEVEL0 "  "
#define GRAYLEVEL1 "||"
#define GRAYLEVEL2 "ii"
#define GRAYLEVEL3 "!!"
#define GRAYLEVEL4 "II"
#define GRAYLEVEL5 "[]"
#define GRAYLEVEL6 "##"
#define GRAYLEVEL7 "@@"

#define BINARY_ARGV_1 80 //二值化参数1
#define BINARY_ARGV_2 255 //二值化参数2 大于0，小于225

#define waitSecond 10 //字符画刷新间隔
#define zipTimes 9 //图像缩放大小
#define printPercison 4 //字符画取样参数

#define SAMPLE_INTERVAL 5 //视频取样间隔

class Img {
public:
	void outputStringPainting(Mat& image, int percison, int flag_printerchar_type);//将一个Mat对象转化为字符画在终端输出
	void printchar_black(int pv, int k); //不同灰度字符串输出样式输出样式， k为字符画取样参数， 每k个灰度合并为一个符号
	void printchar_white(int pv, int k); //不同灰度字符串输出样式输出样式， k为字符画取样参数， 每k个灰度合并为一个符号
	
	void zip(Mat& image, int a, int b); //自定义尺寸缩放
	void zip_equal(Mat& image, int n, int flag_print = 0);  //按比例缩小n倍

	void picturesToStringPaintings(const std::string destination_folder, const std::string filename, const std::string file_format, int sum, int flag_printerchar_type);
	// 将同一文件夹中一组图片按编号转化为字符画输出到终端中
	//	格式 ($ destination_folder 文件夹地址)/($ filename 统一文件名)($ number 编号).($ file_format 图片格式)
	// 规定：从 0 开始，到 sum - 1 结束，共读取并转化 sum 张图片

	int getFrame(const std::string sourcse_address, const std::string destination_folder, const std::string filename, const std::string file_format);
	// 将视频帧转成图片输出
};
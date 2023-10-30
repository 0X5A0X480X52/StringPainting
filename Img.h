#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

// >>  ||ii!!II][##@@
#define GRAYLEVEL0 "  "
#define GRAYLEVEL1 "||"
#define GRAYLEVEL2 "ii"
#define GRAYLEVEL3 "!!"
#define GRAYLEVEL4 "II"
#define GRAYLEVEL5 "[]"
#define GRAYLEVEL6 "##"
#define GRAYLEVEL7 "@@"

class Img {
public:
	void outputStringPainting(Mat& image, int percison);
	void printchar(int pv, int k);
	
	void zip(Mat& image, int a, int b);
	void zip_equal(Mat& image, int n, int flag_print = 0);
	void ikun();
	void ikun_02();
	void ikun_03();
	void ikun_04();

	void getFrame();
	void getFrame_01();
};
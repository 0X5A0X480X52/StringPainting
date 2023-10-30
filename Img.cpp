#include "Img.h"

//将一个Mat对象转化为字符画在终端输出
void Img::outputStringPainting(Mat& image, int percison, int flag_printerchar_type = 0)
{
	int height = image.cols;
	int width = image.rows;
	int pv;

	//将图片转化为灰度图，二值化，取单通道
	Mat gray, gray_T;
	std::vector<Mat> planes;
	cvtColor(image, gray_T, COLOR_BGR2GRAY);
	threshold(gray_T, gray, BINARY_ARGV_1, BINARY_ARGV_2, THRESH_TOZERO);
	split(gray, planes);

	//在终端中打印字符画
	for (int row = 0; row < width; row++) {
		uchar* current_row = planes[0].ptr<uchar>(row);
		for (int col = 0; col < height; col++) {
			pv = *current_row++;
			if (flag_printerchar_type == 0) {
				printchar_black(pv, percison);
			}
			else {
				printchar_white(pv, percison);
			}
		}
		std::cout << "\n";
	}
}

//不同灰度字符串输出样式输出样式， k为字符画取样参数， 每k个灰度合并为一个符号
void Img::printchar_black(int pv, int k)
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

void Img::printchar_white(int pv, int k)
{
	if (pv < k) {
		std::cout << GRAYLEVEL0;
	}
	else if (pv < k * 2) {
		std::cout << GRAYLEVEL1;
	}
	else if (pv < k * 3) {
		std::cout << GRAYLEVEL2;
	}
	else if (pv < k * 4) {
		std::cout << GRAYLEVEL3;
	}
	else if (pv < k * 5) {
		std::cout << GRAYLEVEL4;
	}
	else if (pv < k * 6) {
		std::cout << GRAYLEVEL5;
	}
	else if (pv < k * 7) {
		std::cout << GRAYLEVEL6;
	}
	else {
		std::cout << GRAYLEVEL7;
	}
}

//自定义尺寸缩放
void Img::zip(Mat& image, int a, int b)
{
	//照片result1.jpg改变像素（尺寸大小）
	Size srcSize = Size(a, b);  //填入任意指定尺寸
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	imshow("压缩图", image);
}

//按比例缩小n倍
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

// 将同一文件夹中一组图片按编号转化为字符画输出到终端中
//	格式 ($ destination_folder 文件夹地址)/($ filename 统一文件名)($ number 编号).($ file_format 图片格式)
// 规定：从 0 开始，到 sum - 1 结束，共读取并转化 sum 张图片
void Img::picturesToStringPaintings(const std::string destination_folder, const std::string filename, const std::string file_format, int sum, int flag_printerchar_type = 0)
{
	Mat* pImg;
	std::string destination;

	for (int i = 0; i < sum ; i++) {
		//读取图片
		pImg = new Mat;
		destination = destination_folder + '/' + filename;
		*pImg = cv::imread(destination + std::to_string(i) + '.' + file_format);
		
		// 压缩并转化输出
		zip_equal(*pImg, zipTimes);
		outputStringPainting(*pImg, printPercison, flag_printerchar_type);
		
		waitKey(waitSecond);
		system("cls");
		delete pImg;
	}
}

// 将视频帧转成图片输出
int Img::getFrame(const std::string sourcse_address, const std::string destination_folder, const std::string filename, const std::string file_format)
{
	// 获取视频文件
	VideoCapture cap(sourcse_address);
	std::cout << sourcse_address << std::endl;
	if (!cap.isOpened()) {
		//如果视频不能正常打开则返回
		std::cout << "Error : Fail to open the video" << std::endl;
		return -1;
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
		str << filename << outputFrame << '.' << file_format;
		std::cout << "正在处理第" << currentFrame << "帧" << std::endl;
		printf("\n");

		// 设置每 SAMPLE_INTERVAL 帧获取一次帧
		if (currentFrame % SAMPLE_INTERVAL == 0) {
			// 将帧转成图片输出
			imwrite(destination_folder + '/' + str.str(), frame);
			std::cout << ">>输出为第" << outputFrame << "帧" << "\n\tdestination" << destination_folder + '/' + str.str() << std::endl;
			printf("\n");
			outputFrame++;
		}
		// 结束条件
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	std::cout << ">>采样结束\n\t共采样产生 " << outputFrame - 1 << "帧图片\n" << "\t采样输出文件夹: " << destination_folder << std::endl;
	system("pause");
	return outputFrame;
}
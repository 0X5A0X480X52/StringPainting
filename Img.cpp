#include "Img.h"

//��һ��Mat����ת��Ϊ�ַ������ն����
void Img::outputStringPainting(Mat& image, int percison, int flag_printerchar_type = 0)
{
	int height = image.cols;
	int width = image.rows;
	int pv;

	//��ͼƬת��Ϊ�Ҷ�ͼ����ֵ����ȡ��ͨ��
	Mat gray, gray_T;
	std::vector<Mat> planes;
	cvtColor(image, gray_T, COLOR_BGR2GRAY);
	threshold(gray_T, gray, BINARY_ARGV_1, BINARY_ARGV_2, THRESH_TOZERO);
	split(gray, planes);

	//���ն��д�ӡ�ַ���
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

//��ͬ�Ҷ��ַ��������ʽ�����ʽ�� kΪ�ַ���ȡ�������� ÿk���ҶȺϲ�Ϊһ������
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

//�Զ���ߴ�����
void Img::zip(Mat& image, int a, int b)
{
	//��Ƭresult1.jpg�ı����أ��ߴ��С��
	Size srcSize = Size(a, b);  //��������ָ���ߴ�
	resize(image, image, srcSize, 0, 0, INTER_LINEAR);
	std::cout << image.size() << std::endl;
	imshow("ѹ��ͼ", image);
}

//��������Сn��
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

// ��ͬһ�ļ�����һ��ͼƬ�����ת��Ϊ�ַ���������ն���
//	��ʽ ($ destination_folder �ļ��е�ַ)/($ filename ͳһ�ļ���)($ number ���).($ file_format ͼƬ��ʽ)
// �涨���� 0 ��ʼ���� sum - 1 ����������ȡ��ת�� sum ��ͼƬ
void Img::picturesToStringPaintings(const std::string destination_folder, const std::string filename, const std::string file_format, int sum, int flag_printerchar_type = 0)
{
	Mat* pImg;
	std::string destination;

	for (int i = 0; i < sum ; i++) {
		//��ȡͼƬ
		pImg = new Mat;
		destination = destination_folder + '/' + filename;
		*pImg = cv::imread(destination + std::to_string(i) + '.' + file_format);
		
		// ѹ����ת�����
		zip_equal(*pImg, zipTimes);
		outputStringPainting(*pImg, printPercison, flag_printerchar_type);
		
		waitKey(waitSecond);
		system("cls");
		delete pImg;
	}
}

// ����Ƶ֡ת��ͼƬ���
int Img::getFrame(const std::string sourcse_address, const std::string destination_folder, const std::string filename, const std::string file_format)
{
	// ��ȡ��Ƶ�ļ�
	VideoCapture cap(sourcse_address);
	std::cout << sourcse_address << std::endl;
	if (!cap.isOpened()) {
		//�����Ƶ�����������򷵻�
		std::cout << "Error : Fail to open the video" << std::endl;
		return -1;
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
		str << filename << outputFrame << '.' << file_format;
		std::cout << "���ڴ����" << currentFrame << "֡" << std::endl;
		printf("\n");

		// ����ÿ SAMPLE_INTERVAL ֡��ȡһ��֡
		if (currentFrame % SAMPLE_INTERVAL == 0) {
			// ��֡ת��ͼƬ���
			imwrite(destination_folder + '/' + str.str(), frame);
			std::cout << ">>���Ϊ��" << outputFrame << "֡" << "\n\tdestination" << destination_folder + '/' + str.str() << std::endl;
			printf("\n");
			outputFrame++;
		}
		// ��������
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	std::cout << ">>��������\n\t���������� " << outputFrame - 1 << "֡ͼƬ\n" << "\t��������ļ���: " << destination_folder << std::endl;
	system("pause");
	return outputFrame;
}
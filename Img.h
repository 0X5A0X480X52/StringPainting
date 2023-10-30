#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

// �����ַ����ڱ�ʾ��ͬ�Ҷȵ�����>>  ||ii!!II][##@@
#define GRAYLEVEL0 "  "
#define GRAYLEVEL1 "||"
#define GRAYLEVEL2 "ii"
#define GRAYLEVEL3 "!!"
#define GRAYLEVEL4 "II"
#define GRAYLEVEL5 "[]"
#define GRAYLEVEL6 "##"
#define GRAYLEVEL7 "@@"

#define BINARY_ARGV_1 80 //��ֵ������1
#define BINARY_ARGV_2 255 //��ֵ������2 ����0��С��225

#define waitSecond 10 //�ַ���ˢ�¼��
#define zipTimes 9 //ͼ�����Ŵ�С
#define printPercison 4 //�ַ���ȡ������

#define SAMPLE_INTERVAL 5 //��Ƶȡ�����

class Img {
public:
	void outputStringPainting(Mat& image, int percison, int flag_printerchar_type);//��һ��Mat����ת��Ϊ�ַ������ն����
	void printchar_black(int pv, int k); //��ͬ�Ҷ��ַ��������ʽ�����ʽ�� kΪ�ַ���ȡ�������� ÿk���ҶȺϲ�Ϊһ������
	void printchar_white(int pv, int k); //��ͬ�Ҷ��ַ��������ʽ�����ʽ�� kΪ�ַ���ȡ�������� ÿk���ҶȺϲ�Ϊһ������
	
	void zip(Mat& image, int a, int b); //�Զ���ߴ�����
	void zip_equal(Mat& image, int n, int flag_print = 0);  //��������Сn��

	void picturesToStringPaintings(const std::string destination_folder, const std::string filename, const std::string file_format, int sum, int flag_printerchar_type);
	// ��ͬһ�ļ�����һ��ͼƬ�����ת��Ϊ�ַ���������ն���
	//	��ʽ ($ destination_folder �ļ��е�ַ)/($ filename ͳһ�ļ���)($ number ���).($ file_format ͼƬ��ʽ)
	// �涨���� 0 ��ʼ���� sum - 1 ����������ȡ��ת�� sum ��ͼƬ

	int getFrame(const std::string sourcse_address, const std::string destination_folder, const std::string filename, const std::string file_format);
	// ����Ƶ֡ת��ͼƬ���
};
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("./lenna.jpg", IMREAD_GRAYSCALE); 
	Mat blur, th1, th2, th3, th4;
	threshold(src, th1, 127, 255, THRESH_BINARY);
	threshold(src, th2, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Size size = Size(5, 5);
	GaussianBlur(src, blur, size, 0);
	threshold(blur, th3, 0, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("Original", src);
	imshow("Global", th1);
	imshow("Ostu", th2);
	imshow("Ostu after Blurring", th3); // 블러링을 통해 잡음이 제거되어 작은 흰부분이 검정색이되었다.
	waitKey();
	return 0;

}
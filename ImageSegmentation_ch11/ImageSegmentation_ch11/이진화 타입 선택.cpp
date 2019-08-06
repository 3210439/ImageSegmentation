#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int threshold_value = 128;
int threshold_type = 0;
const int max_type = 4;
const int max_binary_value = 255;
Mat src, src_gray, dst;

static void MyThreshold(int, void*)
{
	threshold(src, dst, threshold_value, max_binary_value, threshold_type);
	imshow("result", dst);
}

int main()
{
	src = imread("./lenna.jpg", IMREAD_GRAYSCALE);
	imshow("src", src);
	namedWindow("result", WINDOW_AUTOSIZE);
	createTrackbar("Type: \n 0: Binary \n 1:Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted"
		, "result", &threshold_type, max_type, MyThreshold);

	MyThreshold(0, 0);
	waitKey(0);
	return 0;
}
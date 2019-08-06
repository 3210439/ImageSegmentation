#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main() // 이것은 가우시안 혼합 기반 배경 / 전경 분할 알고리즘이다.
{
	Mat frame;	// 현재 프레임
	Mat result; // MOG2에 의하여 생성되는 결과 영상
	Ptr<BackgroundSubtractor> pMOG2; // MOG2 배경 삭제 객체
	int keyboard =0;

	pMOG2 = createBackgroundSubtractorMOG2();
	VideoCapture capture("./tennis.mp4");
	if (!capture.isOpened()) { exit(EXIT_FAILURE); }

	while ((char)keyboard != 27) {
		if (!capture.read(frame)) exit(EXIT_FAILURE);
		pMOG2->apply(frame, result);
		imshow("Frame", frame);
		imshow("FG Mask MOG 2", result);
		keyboard = waitKey(30);
	}
	
	capture.release();
	return 0;
}
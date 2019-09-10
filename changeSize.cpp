#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
int main(int argc, char** argv)
{
	Mat imgSrc = imread("D:\\source\\pictures\\1589x601.png");
	Mat imgDst;
	Size outputSize;
	double fx = 0.5, fy = 0.5;
	outputSize = Size(120,60);
	resize(imgSrc,imgDst,outputSize);
	imshow("1", imgDst);
	imwrite("D:\\source\\pictures\\120x60.png",imgDst);
	waitKey(0);
	destroyWindow("1");
	return 0;
}
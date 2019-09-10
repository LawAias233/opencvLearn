#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	cv::Mat imgSrc = cv::imread("D:\\source\\pictures\\1024x768.png");
	cv::Mat imgDst;
	//cv::blur(imgSrc,imgDst,cv::Size(5,5),cv::Point(-1,-1));//一般滤波

	//cv::medianBlur(imgSrc,imgDst,5);//中值滤波,默认核的中心点为锚点,

	//cv::GaussianBlur(imgSrc,imgDst,cv::Size(5,5),0,0,CV_HAL_BORDER_CONSTANT);
	//最后一个参数与bodertype相同

	//cv::bilateralFilter(imgSrc,imgDst,5,150,150);
	//双边滤波

	//cv::Sobel(imgSrc,imgDst,CV_32F,1,1,3,0.5,0,4);

	cv::imshow("src", imgSrc);
	cv::imshow("dst", imgDst);
	cv::waitKey(0);
	return 0;
}
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	cv::Mat imgSrc = cv::imread("D:\\source\\pictures\\1024x768.png");
	cv::Mat imgDst;

	//@腐蚀膨胀
	//cv::dilate(imgSrc,imgDst,cv::Mat(),cv::Point(-1,-1),1,cv::BORDER_CONSTANT);//腐蚀操作
	//cv::erode(imgSrc,imgDst,cv::Mat(),cv::Point(-1,-1),1,cv::BORDER_CONSTANT);//膨胀操作

	//@开闭操作
	//开操作，先对图像进行腐蚀然后再膨胀 MORPH_OPEN 常用于分离两个靠的很近的形状
	//cv::morphologyEx(imgSrc,imgDst,cv::MORPH_OPEN,cv::Mat(),cv::Point(-1,-1),1,cv::BORDER_CONSTANT);

	//闭操作，先对图像膨胀再腐蚀 MORPH_CLOSE 常用于连通分支
	//cv::morphologyEx(imgSrc,imgDst,cv::MORPH_CLOSE,cv::Mat(),cv::Point(-1,-1),1,cv::BORDER_CONSTANT);

	//对于非布尔型图像进行形态学操作时，闭操作善于消除小于领域内点的孤立异常值，开操作善于消除大于的异常值 p250

	//@形态学操作  gradient(src) = dilate(src) - erode(src)
	//形态学操作 扩张亮域（膨胀）的结果减去缩减亮域（腐蚀）的结果得到图像的边缘 MORPH_GARDIENT
	//cv::morphologyEx(imgSrc,imgDst,cv::MORPH_GRADIENT,cv::Mat(),cv::Point(-1,-1),1,cv::BORDER_CONSTANT);

	//@顶帽黑帽
	//顶帽 TopHat(src) = src - open(src) 
	//用源图像减去对其开操作后的图像得到比原图更亮的环绕部分 似乎可以用来提取文字 背景较深时效果好
	//cv::morphologyEx(imgSrc, imgDst, cv::MORPH_TOPHAT, cv::Mat(), cv::Point(-1, -1), 1, cv::BORDER_CONSTANT);

	//黑帽 BlackHat(src) = close(src) - src
	//用闭图像减去原图像 得到比源图像更暗的环绕部分 提取文字，背景较文字颜色浅时
	//cv::morphologyEx(imgSrc, imgDst, cv::MORPH_BLACKHAT, cv::Mat(), cv::Point(-1, -1), 1, cv::BORDER_CONSTANT);
	
	//@自定义核
	//cv::Mat myElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3),cv::Point(-1,-1));

	//用nx1 和 1xn 的两个线性滤波器代替nxn的核进行卷积，当n>3时可节省效率
	//A为被处理图像面积,前者消耗为 2An, 后者为An^2
	//cv::Mat myKern = (cv::Mat_<char>(3, 3) << 0, 1, 0,
	//											1, 1, 1,
	//											0, 1, 0);
	//cv::filter2D(imgSrc,imgDst,imgSrc.depth(),myKern,cv::Point(-1,-1),0,cv::BORDER_DEFAULT);

	//分核
	//分为两个一维核进行计算
	//cv::Mat myKernX = (cv::Mat_<char>(1, 3) << 1, 2, 1);
	//cv::Mat myKernY = (cv::Mat_<char>(3, 1) << -1, 0, 1);
	//cv::sepFilter2D(imgSrc,imgDst,imgSrc.depth(),myKernX,myKernY,cv::Point(-1,-1),0,cv::BORDER_DEFAULT);

	//@用于生成一些特定卷积核的函数
	//生成Sobel与Scharr
	//cv::Mat myKern0, myKern1, myKern2;//接收
	//cv::getDerivKernels(myKern1,myKern2,1,1,3,true,CV_32F);
	
	//高斯卷积核
	//cv::getGaussianKernel(3,-1,CV_32F);

	cv::imshow("src", imgSrc);
	cv::imshow("dst", imgDst);
	cv::waitKey(0);
	return 0;
}
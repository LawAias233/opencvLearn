#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>

int main(int argc, char** argv)
{
	cv::Mat imgSrc = cv::imread("D:\\source\\pictures\\1024x768.png");
	cv::Mat imgDst;
	
	//@图像处理
	//cv::pyrDown(imgSrc,imgDst,cv::Size(imgSrc.cols/2,imgSrc.rows/2));
	//预设不设定dsize的情况下默认为丢弃偶数行列,即缩为原图的1/4,
	//与其相反的有pyrUp;

	//@图像金字塔
	/*std::vector<cv::Mat> imgS;
	cv::buildPyramid(imgSrc, imgS, 3);
	std::string title;
	std::vector<cv::Mat>::iterator itbegin = imgS.begin();
	std::vector<cv::Mat>::iterator itend = imgS.end();
	for (int i = 0; itbegin < itend; itbegin++, i++) {
		title = i;
		cv::namedWindow(title);
		cv::imshow(title,*itbegin);
	}*/

	//@拉普拉斯金字塔
	//待填坑

	//不均匀映射
	//用2x3矩阵来变换的‘仿射变换’ 与 用3x3矩阵来变换的‘透视变换’或称‘同形’

	//@仿射变换
	//A=[[a1,a2],[a3,a4]] ; B = [[b1],[b2]] ' X = [x,y]
	//[A,B]=[[a1,a2,b1],[a3,a4,b2]] 
	//T = AX + B = [A,B][[x],[y],[1]];
	//对于矩形，仿射变换可以将其变为边仍然平行的平行四边形，同时实现旋转或缩放
	/*cv::Point2f triSrc[3], triDst[3];
	triSrc[0] = cv::Point2f(0,0);
	triSrc[1] = cv::Point2f(imgSrc.cols-1,0);
	triSrc[2] = cv::Point2f(0,imgSrc.rows-1);
	triDst[0] = cv::Point2f(imgSrc.cols/2, 0);//cosθ= 45°
	triDst[1] = cv::Point2f(imgSrc.cols-1, 0);
	triDst[2] = cv::Point2f(0, imgSrc.rows/2);//垂直方向进行了两倍的缩小
	cv::Mat mo = cv::getAffineTransform(triSrc, triDst);//计算仿射矩阵
	//三个点意为三角形，在原图确定中三个点，在目标图像中确定三个点的新位置，根据比例得到仿射矩阵
	cv::warpAffine(imgSrc,imgDst,mo,cv::Size(imgSrc.cols,imgSrc.rows),cv::INTER_LINEAR,cv::BORDER_CONSTANT);
	cv::Mat ro = cv::getRotationMatrix2D(cv::Point(imgDst.cols / 2, imgDst.rows/2),-50,1);//顺时针旋转50°，放缩比例不变
	cv::warpAffine(imgDst, imgDst, ro, imgDst.size());
	//@逆仿射变换 已知仿射矩阵，得到可以使图像变回仿射前样子的逆仿射矩阵
	ro = cv::getRotationMatrix2D(cv::Point(imgDst.cols / 2, imgDst.rows / 2), 50, 1);//把图转回来XD
	cv::warpAffine(imgDst, imgDst, ro, imgDst.size());
	cv::Mat imo;
	cv::invertAffineTransform(mo,imo);
	cv::warpAffine(imgDst,imgDst,imo,imgDst.size());
	//虽然变回来了，但是显而易见的是丢失了很多的像素点
	*/


	cv::imshow("src", imgSrc);
	cv::imshow("dst", imgDst);
	cv::waitKey(0);
	return 0;
}
/*******************************************************************************
    >  File Name: 1th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月16日 星期一 17时46分18秒
*******************************************************************************/

/*
 * 图像显示
 */

#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char* argv[])
{
    Mat srcImage = imread("1.jpg"); //载入图像
    imshow("【原始图】", srcImage); //显示图像
    waitKey(0);                     //等待任意键按下
    return 0;
}

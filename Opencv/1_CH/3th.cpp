/*******************************************************************************
    >  File Name: 3th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 01时02分54秒
*******************************************************************************/

/*
 *  均值滤波
 */

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(void)
{
    Mat srcImage = imread("3.jpg");
    imshow("【原图】均值滤波", srcImage);
    Mat dstImage;
    blur(srcImage, dstImage, Size(7, 7));
    imshow("【效果图】均值滤波", dstImage);
    waitKey(0);

    return 0;
}

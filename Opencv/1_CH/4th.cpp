/*******************************************************************************
    >  File Name: 4th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 01时09分21秒
*******************************************************************************/

/*
 *  边缘检测
 */

#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
    Mat srcImage = imread("4.jpg");
    imshow("【原始图】边缘检测", srcImage);

    Mat dstImage, edge, grayImage;
    dstImage.create(srcImage.size(), srcImage.type());
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    blur(grayImage, edge, Size(3, 3));
    Canny(edge, edge, 3, 9, 3);

    imshow("【效果图】边缘检测", edge);
    waitKey(0);

    return 0;
}

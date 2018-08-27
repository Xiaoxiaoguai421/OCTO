/*******************************************************************************
    >  File Name: 2th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月16日 星期一 18时06分27秒
*******************************************************************************/

/*
 * 图像腐蚀
 */

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat srcImage = imread("2.jpg");
    imshow("【原图】腐蚀操作", srcImage);
    //腐蚀
    Mat elemnt = getStructuringElement(MORPH_RECT, Size(20, 20)); //返回指定形状和尺寸的结构元素(内核矩阵)
    Mat dstImage;
    erode(srcImage, dstImage, elemnt);

    imshow("【效果图】腐蚀操作", dstImage);
    waitKey(0);

    return 0;
}

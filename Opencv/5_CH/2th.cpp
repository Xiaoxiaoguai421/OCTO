/*******************************************************************************
    >  File Name: 2th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月19日 星期四 15时28分44秒
*******************************************************************************/

/*
 *  图像的对比度和亮度
 *  g(i,,j) = a*f(i,j) + b
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
static void on_ContrastAndBright(int, void*);

#define WINDOW_NAME "【效果图窗口】"
int g_nContrastValue = 80;
int g_nBrightValue = 80;
Mat g_srcImage, g_dstImage;

int main(void)
{
    g_srcImage = imread("2.jpg");
    g_dstImage.create(g_srcImage.rows, g_srcImage.cols, g_srcImage.type());

    g_nContrastValue = 80;
    g_nBrightValue = 80;

    namedWindow(WINDOW_NAME);
    createTrackbar("对比度", WINDOW_NAME, &g_nContrastValue, 300, on_ContrastAndBright);
    createTrackbar("亮度", WINDOW_NAME, &g_nBrightValue, 200, on_ContrastAndBright);

    on_ContrastAndBright(g_nContrastValue, 0);
    on_ContrastAndBright(g_nBrightValue, 0);

    waitKey(0);

    return 0;
}

void on_ContrastAndBright(int, void*)
{
    namedWindow("【原始图窗口】");

    //为什么x，y要倒着写
    for (int y = 0; y < g_srcImage.rows; y++)
        for (int x = 0; x < g_srcImage.cols; x++)
            for (int c = 0; c < 3; c++) {
                g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
            }
    imshow("【原始图窗口】", g_srcImage);
    //    moveWindow("【原始图窗口", 0, 200);
    imshow(WINDOW_NAME, g_dstImage);
    //    Rect rect(0, 200, g_srcImage.cols, g_srcImage.rows);
    //    moveWindow(WINDOW_NAME, rect.height, 200);
}

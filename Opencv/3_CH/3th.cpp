/*******************************************************************************
    >  File Name: 3th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 17时28分13秒
*******************************************************************************/

/*
 *  轨迹条控制两幅图像的Alpha混合
 */

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "【线性混合示例】"
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int, void*)
{
    g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
    g_dBetaValue = (1.0 - g_dAlphaValue);

    addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0, g_dstImage);
    imshow(WINDOW_NAME, g_dstImage);
}

int main(void)
{
    g_srcImage1 = imread("3_1.jpg");
    g_srcImage2 = imread("3_2.jpg");

    g_nAlphaValueSlider = 70;
    namedWindow(WINDOW_NAME, 1);

    char TrackbarName[50];
    sprintf(TrackbarName, "透明度 %d", g_nMaxAlphaValue);

    createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
    on_Trackbar(g_nAlphaValueSlider, 0);

    waitKey(0);

    return 0;
}

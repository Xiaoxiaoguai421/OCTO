#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

Mat g_srcTmage, g_dstImage1, g_dstImage2, g_dstImage3, g_dstImage4, g_dstImage5;
int g_nBoxFilterValue = 6;
int g_nMeanBlurValue = 10;
int g_nGaussianBlurValue = 6;
int g_nMedianBlurValue = 10;
int g_nBilateralFilterValue = 10;

static void on_BoxFilter(int, void*);
static void on_MeanBlur(int, void*);
static void on_GaussianBlur(int, void*);
static void on_MedianBlur(int, void*);
static void on_BilateralFilter(int, void*);

int main(void)
{
    g_srcTmage = imread("1.jpg", 1);
    g_dstImage1 = g_srcTmage.clone();
    g_dstImage2 = g_srcTmage.clone();
    g_dstImage3 = g_srcTmage.clone();
    g_dstImage4 = g_srcTmage.clone();
    g_dstImage5 = g_srcTmage.clone();
    namedWindow("【原图】", 1);
    imshow("【原图】", g_srcTmage);

    namedWindow("【方框滤波】", 1);
    createTrackbar("内核值：", "【方框滤波】", &g_nBoxFilterValue, 50, on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue, 0);
    imshow("【方框滤波】", g_dstImage1);

    namedWindow("【均值滤波】", 1);
    createTrackbar("内核值：", "【均值滤波】", &g_nMeanBlurValue, 50, on_MeanBlur);
    on_MeanBlur(g_nMeanBlurValue, 0);
    imshow("【均值滤波】", g_dstImage2);

    namedWindow("【高斯滤波】", 1);
    createTrackbar("内核值：", "【高斯滤波】", &g_nGaussianBlurValue, 50, on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue, 0);
    imshow("【高斯滤波】", g_dstImage3);

    namedWindow("【中值滤波】", 1);
    createTrackbar("参数值：", "【中值滤波】", &g_nMedianBlurValue, 50, on_MedianBlur);
    on_MedianBlur(g_nMedianBlurValue, 0);
    imshow("【中值滤波】", g_dstImage4);

    namedWindow("【双边滤波】", 1);
    createTrackbar("参数值：", "【双边滤波】", &g_nBilateralFilterValue, 50, on_BilateralFilter);
    on_BilateralFilter(g_nBilateralFilterValue, 0);
    imshow("【双边滤波】", g_dstImage5);

    waitKey(0);

    return 0;
}

static void on_BoxFilter(int, void*)
{
    boxFilter(g_srcTmage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
}
static void on_MeanBlur(int, void*)
{
    blur(g_srcTmage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
}
static void on_GaussianBlur(int, void*)
{
    GaussianBlur(g_srcTmage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
}
static void on_MedianBlur(int, void*)
{
    medianBlur(g_srcTmage, g_dstImage4, g_nMedianBlurValue * 2 + 1);
}
static void on_BilateralFilter(int, void*)
{
    bilateralFilter(g_srcTmage, g_dstImage5, g_nGaussianBlurValue, g_nGaussianBlurValue * 2, g_nGaussianBlurValue / 2);
}

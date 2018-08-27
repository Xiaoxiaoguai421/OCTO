/*******************************************************************************
    >  File Name: 3th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月22日 星期日 09时49分19秒
*******************************************************************************/

/*
 *  傅里叶变换
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat srcImage = imread("3.jpg", 0);
    imshow("原始图像", srcImage);

    // 扩充图片
    int m = getOptimalDFTSize(srcImage.rows);
    int n = getOptimalDFTSize(srcImage.cols);
    Mat padded;
    copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));

    //为傅里叶变换结果分配空间
    Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
    Mat complexI;
    merge(planes, 2, complexI);

    //傅里叶变换
    dft(complexI, complexI);

    //计算幅值
    split(complexI, planes);
    magnitude(planes[0], planes[1], planes[0]);

    //对数尺度缩放
    Mat magnitudeImage = planes[0];
    magnitudeImage += Scalar::all(1);
    log(magnitudeImage, magnitudeImage);

    //提出扩展的像素，重分布幅度图象限
    magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
    int cx = magnitudeImage.cols / 2;
    int cy = magnitudeImage.rows / 2;
    Mat q0(magnitudeImage, Rect(0, 0, cx, cy));
    Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));
    Mat q2(magnitudeImage, Rect(0, cy, cx, cy));
    Mat q3(magnitudeImage, Rect(cx, cy, cx, cy));

    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    // 归一化，将幅度值归一到[0,1]范围内
    normalize(magnitudeImage, magnitudeImage, 0, 1, NORM_MINMAX);
    imshow("频谱幅值", magnitudeImage);
    waitKey(0);

    return 0;
}

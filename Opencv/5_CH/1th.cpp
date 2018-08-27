/*******************************************************************************
    >  File Name: 1th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月18日 星期三 13时40分09秒
*******************************************************************************/

/*
 * 目的：减少图像中颜色数量
 * 1. 使用计时函数：getTickCount() 、getTickFrequency()
 * 2. 访问图中像素的三种方法
 *      -   指针访问 
 *      -   迭代器iterator
 *      -   动态地址计算
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void colorReduce1(Mat& inputImage, Mat& outputImage, int div);
void colorReduce2(Mat& inputImage, Mat& outputImage, int div);
void colorReduce3(Mat& inputImage, Mat& outputImage, int div);
int main(void)
{
    Mat srcImage1 = imread("1_1.jpg");
    Mat srcImage2 = imread("1_2.jpg");
    Mat srcImage3 = imread("1_3.jpg");
    imshow("原始图像", srcImage1);

    Mat dstImage1(srcImage1.rows, srcImage1.cols, srcImage1.type());
    Mat dstImage2(srcImage2.rows, srcImage2.cols, srcImage2.type());
    Mat dstImage3(srcImage3.rows, srcImage3.cols, srcImage3.type());

    double time;

    time = static_cast<double>(getTickCount());
    colorReduce1(srcImage1, dstImage1, 32);
    time = ((double)getTickCount() - time) / getTickFrequency();
    cout << "指针访问 运行时间：" << time << "秒" << endl;
    imshow("效果图1", dstImage1);

    time = static_cast<double>(getTickCount());
    colorReduce2(srcImage2, dstImage2, 32);
    time = ((double)getTickCount() - time) / getTickFrequency();
    cout << "迭代器 运行时间：" << time << "秒" << endl;
    imshow("效果图2", dstImage2);

    time = static_cast<double>(getTickCount());
    colorReduce3(srcImage3, dstImage3, 32);
    time = ((double)getTickCount() - time) / getTickFrequency();
    cout << "动态地址 运行时间：" << time << "秒" << endl;
    imshow("效果图3", dstImage3);

    waitKey(0);

    return 0;
}

void colorReduce1(Mat& inputImage, Mat& outputImage, int div)
{
    outputImage = inputImage.clone();
    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols * outputImage.channels();

    for (int i = 0; i < rowNumber; i++) {
        uchar* data = outputImage.ptr<uchar>(i); //获得第i行的首地址
        for (int j = 0; j < colNumber; j++)
            data[j] = data[j] / div * div + div / 2;
    }
}

void colorReduce2(Mat& inputImage, Mat& outputImage, int div)
{
    outputImage = inputImage.clone();
    Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();
    for (; it != itend; it++) {
        (*it)[0] = (*it)[0] / div * div + div / 2;
        (*it)[1] = (*it)[1] / div * div + div / 2;
        (*it)[2] = (*it)[2] / div * div + div / 2;
    }
}

void colorReduce3(Mat& inputImage, Mat& outputImage, int div)
{
    outputImage = inputImage.clone();
    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols;

    for (int i = 0; i < rowNumber; i++)
        for (int j = 0; j < colNumber; j++) {
            outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
            outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;
            outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;
        }
}

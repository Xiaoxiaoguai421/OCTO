/*******************************************************************************
    >  File Name: 1th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 15时41分49秒
*******************************************************************************/

/*
 * imwrite()函数的用法，在opencv中生成一幅png图片
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

void createAlphaMat(Mat& mat)
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            Vec4b& rgba = mat.at<Vec4b>(i, j);
            rgba[0] = UCHAR_MAX;
            rgba[1] = saturate_cast<uchar>((float)(mat.cols - j)) / ((float)mat.cols * UCHAR_MAX);
            rgba[2] = saturate_cast<uchar>((float)(mat.rows - j)) / ((float)mat.rows * UCHAR_MAX);
            rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
        }
    }
}

int main(void)
{
    //创建带Alpha通道的Mat
    Mat mat(480, 640, CV_8UC4);
    createAlphaMat(mat);

    vector<int> compression_params;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    try {
        imwrite("透明Alph图.png", mat, compression_params);
        imshow("生成的PNG图", mat);
        fprintf(stdout, "PNG图片文件的alpha数据保存完毕~\n可以在工程目录下查看由imwrite函数生成的图片\n");
        waitKey(0);
    } catch (runtime_error& ex) {
        fprintf(stderr, "图片转换PNG格式发生错误:%s\n", ex.what());
        return 1;
    }

    return 0;
}

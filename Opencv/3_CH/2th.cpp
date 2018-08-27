/*******************************************************************************
    >  File Name: 2th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 16时15分36秒
*******************************************************************************/

/*
 *  图像融合
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat cat = imread("2.jpg");
    imshow("【1】猫", cat);

    Mat logo = imread("2_logo.jpg");
    imshow("【2】logo", logo);

    Mat imageROI;
    imageROI = cat(Rect(0, 0, logo.cols, logo.rows));
    addWeighted(imageROI, 0.5, logo, 0.3, 0, imageROI);

    /*
    Mat dstImage;
    // dstImage = cat*0.5 + logo*0.3 + 0
    addWeighted(cat, 0.5, logo, 0.3, 0, dstImage);
    */

    imshow("【3】原画+logo图", cat);
    waitKey(0);

    return 0;
}

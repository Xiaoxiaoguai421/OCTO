/*******************************************************************************
    >  File Name: 5th.cpp
    >  Author: GZ
	>  Mail: 194463810@qq.com
	>  Created Time: 2018年07月17日 星期二 01时23分39秒
*******************************************************************************/

/*
 *  打开摄像头，并进行边缘检测
 */

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
    VideoCapture capture(0); //初始化0时打开摄像头；若播放视频，用视频("video.avi")替换(0)即可
    Mat edges;

    while (true) {
        Mat frame;
        capture >> frame;

        cvtColor(frame, edges, COLOR_BGR2GRAY);
        blur(edges, edges, Size(7, 7));
        Canny(edges, edges, 0, 30, 3);

        imshow("被Canny后的视频", edges);
        if (waitKey(30) >= 0)
            break;
    }

    return 0;
}

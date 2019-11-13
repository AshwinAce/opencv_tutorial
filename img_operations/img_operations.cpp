/***** Image operations ******
This code is primarily for knowing how to access pixel values and modify them.
It also includes the fillPoly function that can be used fir drawing shapes
******/
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "time.h"
#include <map>
#include <fstream>

int main() {
	cv::RNG rng(0x00000000);
	cv::Point a(0, 0), b(200, 0), c(100, 173);
	//create a black image
	cv::Mat img(201, 201, CV_8UC3, cv::Scalar(0, 0, 0));
	//how to deep copy images
	cv::Mat res=img.clone();
	cv::Point pt[1][3];
	pt[0][0] = a;
	pt[0][1] = b;
	pt[0][2] = c;
	const cv::Point* ppt[3] = { pt[0] };
	int npt[] = { 3 };
	//in this case, fillPoly fills a triangle, but can be extended to bigger figures
	cv::fillPoly(img, ppt, npt, 1, cv::Scalar(255, 255, 255), 1);
	//section to calculate slopes of lines, not used elsewhere; to show Point manipulation
	float m1,m2,m3,c1,c2,c3;
	m1=(b.y-a.y)/(b.x-a.x);
	m2=(b.y-c.y)/(b.x-c.x);
	m3=(c.y-a.y)/(c.x-a.x);
	img.at<cv::Vec3b>(0,0)[1]=0;
	img.at<cv::Vec3b>(0,0)[2]=0;
	img.at<cv::Vec3b>(0,200)[0]=0;
	img.at<cv::Vec3b>(0,200)[2]=0;
	img.at<cv::Vec3b>(173,100)[1]=0;
	img.at<cv::Vec3b>(173,100)[0]=0;

	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			if(img.at<cv::Vec3b>(i,j)[0]==255 and img.at<cv::Vec3b>(i,j)[1]==255){
				float dist1=sqrt((i*i+j*j));
				float dist2=sqrt(i*i+(j-200)*(j-200));
				float dist3=sqrt((i-173)*(i-173)+(j-100)*(j-100));
				if(dist1>200)
					dist1=200;
				if(dist2>200)
					dist2=200;
				if(dist3>200)
					dist3=200;
				res.at<cv::Vec3b>(i,j)[0]=(200-dist1)*255;
				res.at<cv::Vec3b>(i,j)[1]=(200-dist2)*255;
				res.at<cv::Vec3b>(i,j)[2]=(200-dist3)*255;
			}
		}
	}
	cv::imshow("img", img);
	cv::imshow("res", res);
	cv::waitKey(0);
}

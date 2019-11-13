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

//Tomato segmentation

int main(int argc, char**argv){
	cv::Mat img,gray,kernel,open,close,mask;
	try{
		img = cv::imread(argv[1],1);
	}
	catch(cv::Exception& e){
		std::cout<<"Exception"<<e.what()<<std::endl;
	}

	if( !img.data ){ 
		std::cout<<"Unable to read image\n";
		return 	EXIT_FAILURE; 
	}
	cv::Mat R = cv::Mat(img.rows, img.cols, CV_8UC3, cv::Scalar(0,0,0));
	open=R.clone();
	cv::cvtColor(img,gray, cv::COLOR_BGR2GRAY);
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			if(((img.at<cv::Vec3b>(i,j)[2]-img.at<cv::Vec3b>(i,j)[1])>50)&&((img.at<cv::Vec3b>(i,j)[2]-img.at<cv::Vec3b>(i,j)[0])>50)){

				R.at<cv::Vec3b>(i,j)[0]=255;
				R.at<cv::Vec3b>(i,j)[1]=255;
				R.at<cv::Vec3b>(i,j)[2]=255;
			}
		}
	}
	
	kernel=cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5,5),cv::Point(-1,-1));
	cv::morphologyEx(R,open, cv::MORPH_OPEN,kernel, cv::Point(-1,-1),0,1,1);
	cv::morphologyEx(open,close, cv::MORPH_CLOSE,kernel, cv::Point(-1,-1),2,1,1);
	//morphologyEx(close,open, MORPH_OPEN,kernel, Point(-1,-1),10,1,1);
	
	cv::Mat close_gray;
	cv::cvtColor(close,close_gray,cv::COLOR_BGR2GRAY);
	cv::GaussianBlur( close_gray, close_gray, cv::Size(9, 9), 2, 2 );
	std::vector<cv::Vec3f> circles;
	cv::HoughCircles( close_gray, circles, cv::HOUGH_GRADIENT, 1, close_gray.rows/10, 100, 20, 10, 0 );
	for( size_t i = 0; i < circles.size(); i++ )
	{
	   cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	   int radius = cvRound(circles[i][2]);
	   // circle center
	   cv::circle( img, center, 3, cv::Scalar(0,0,0), -1, 8, 0 );
	   // circle outline
	   cv::circle( img, center, radius, cv::Scalar(255,0,0), 3, 8, 0 );
	 }
	//cv::namedWindow( "Hough Circle Transform Demo", WINDOW_AUTOSIZE );
	cv::imshow( "Hough Circle Transform Demo", img );

	//cv::imshow("open",open);
	cv::imshow("close",close);
	//cv::imshow("r",R);
	//cv::imshow("close_gray",close_gray);
	cv::waitKey(0);
	return EXIT_SUCCESS;
}

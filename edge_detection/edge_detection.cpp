/*****Edge detection*****
This code has filters used in edge detection such as Sobel, Scharr, Canny and Laplacian
******/
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
int main(int argc, char**argv){
	cv::Mat frame,mask,res,kernel,laplace,sobelx,sobely,edges,scharrx,scharry,img;
	try{
		img = cv::imread(argv[1],1);
	}
	catch(cv::Exception& e){
		std::cout<<"Exception"<<e.what()<<std::endl;
	}

	if( !img.data ){ 
		std::cout<<"Unable to read image\n";
		return EXIT_FAILURE; 
	}
	cv::cvtColor(img,frame,cv::COLOR_BGR2GRAY);
	cv::Laplacian(frame,laplace,CV_64F);
	cv::Scharr(frame,scharrx,CV_64F,1,0,5);
	cv::Scharr(frame,scharry,CV_64F,0,1,5);
	cv::Sobel(frame,sobelx,CV_64F,1,0,5);
	cv::Sobel(frame,sobely,CV_64F,0,1,5);
	cv::Canny(frame,edges,20,20,5);
	cv::imshow("laplacian",laplace);
	cv::imshow("sobelx",sobelx);
	cv::imshow("sobely",sobely);
	cv::imshow("scharrx",scharrx);
	cv::imshow("scharry",scharry);
	cv::imshow("Canny",edges);
	cv::waitKey(0);
	return EXIT_SUCCESS;
}

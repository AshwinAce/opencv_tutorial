/******Thresholding******
This code shows some basic thresholding operations.
It also introduces the concept of adaptive thresholding where thresholding is applied locally instead of globally.
*******/
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
int main(int argc, char **argv){
	if(argc==1){
		std::cout<<"No images given\n";
	}
	for(int i=1;i<argc;i++){
		try{
			cv::Mat img,thresh,grayscale,thresh2,gaus,average;
			img=cv::imread(argv[i]);
			if(img.empty()){
				std::cout<<"Unable to read, skipping this \"image\"\n";
				continue;
			}
			cv::threshold(img,thresh,12,255,cv::THRESH_BINARY);
			cv::cvtColor(img,grayscale, cv::COLOR_BGR2GRAY);
			cv::threshold(grayscale,thresh2,12,255,cv::THRESH_BINARY);
			cv::adaptiveThreshold(grayscale,gaus,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY,115,1);
			cv::adaptiveThreshold(grayscale,average,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,115,1);
			cv::imshow("thresh",thresh);
			cv::imshow("thresh2",thresh2);
			cv::imshow("Gaussian",gaus);
			cv::imshow("mean",average);
			cv::waitKey(0);
		}
		catch(cv::Exception& e){
			std::cout<<"Exception"<<e.what()<<std::endl;
		}
	}
	return 0;
}


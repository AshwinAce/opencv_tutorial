#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
int main(int argc,char **argv){
	if(argc==1){
		std::cout<<"No images given\n";
	}
	for(int i=1; i<argc;i++){
		try{
			cv::Mat img,mask,hsv,res,blurr,gaus,med,bilateral,mask_img;
			img=cv::imread(argv[i]);
			if(img.empty()){
				std::cout<<"Unable to read, skipping this \"image\"\n";
				continue;
			}
			//mask that gets all values that have red pixels in range[150,255]
			cv::inRange(img,cv::Scalar(0,0,150),cv::Scalar(255,255,255),mask);
			cv::bitwise_and(img,img,mask_img,mask);
			res=img;
			//various filters performing different operation
			cv::blur(res,blurr,cv::Size(5,5));
			cv::GaussianBlur(res,gaus,cv::Size(5,5),0,0);
			cv::medianBlur(res,med,5);
			cv::bilateralFilter(res,bilateral,5,75,75);

			cv::imshow("Img",img);
			cv::imshow("Mask",mask);
			cv::imshow("Mask on img",mask_img);
			cv::imshow("Mean",blurr);
			cv::imshow("Gaussian",gaus);
			cv::imshow("Median",med);
			cv::imshow("Bilateral",bilateral);
			cv::waitKey(0);	
		}
		catch(cv::Exception& e){
			std::cout<<"Exception"<<e.what()<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}

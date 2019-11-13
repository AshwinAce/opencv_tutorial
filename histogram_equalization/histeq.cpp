#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
void histeq(cv::Mat &img1, cv::Mat& img2);
int main(int argc,char **argv) {
	cv::Mat img, gray, hsv;
	if(argc==1){
		img = cv::imread("/home/username/opencv_tutorial/pics/tomato.jpg");
	}
	else{
		try{
			img = cv::imread(argv[1],1);
		}
		catch(cv::Exception& e){
			
			std::cout<<"Exception"<<e.what()<<std::endl;
		}
	}
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
	cv::Mat hist(img.rows, img.cols, CV_8UC1);
	histeq(gray, hist);
	cv::Mat bgr[3];
	cv::split(img, bgr);
	std::vector<cv::Mat> channels;
	cv::Mat dummy(img.rows, img.cols, CV_8UC1), dummy1, dummy2;
	dummy1 = dummy.clone();
	dummy2 = dummy.clone();

	histeq(bgr[0], dummy);
	//imshow("Blue", dummy);
	channels.push_back(dummy);
	histeq(bgr[1], dummy1);
	//imshow("Green", dummy1);
	channels.push_back(dummy1);
	histeq(bgr[2], dummy2);
	//imshow("Red", dummy2);
	channels.push_back(dummy2);
	cv::Mat rgb_final; //will have a size of(img.rows, img.cols, CV_8UC3);
	cv::merge(channels, rgb_final);
	cv::imshow("Gray", gray);
	cv::imshow("Histeq", hist);
	cv::waitKey(0);	
	cv::imshow("Img", img);	
	cv::imshow("Histeq:bgr", rgb_final);
	cv::waitKey(0);
	cv::Mat ffinal;
	std::vector<cv::Mat> hsvchannels;
	cv::split(hsv, bgr);
	histeq(bgr[2], bgr[2]);
	hsvchannels.push_back(bgr[0]);
	hsvchannels.push_back(bgr[1]);
	hsvchannels.push_back(bgr[2]);
	cv::Mat hsv_equalized;
	cv::merge(hsvchannels, hsv_equalized);
	cv::cvtColor(hsv_equalized, hsv_equalized, cv::COLOR_HSV2BGR);
	cv::imshow("Histeq:hsv", hsv_equalized);
	cv::waitKey(0);
	return EXIT_SUCCESS;
}

//Function that performs histogram equalization on a greyscale matrix
void histeq(cv::Mat &img, cv::Mat &hist) {
	int pdf[256], cdf[256];
	for (int i = 0; i < 256; i++) {
		pdf[i] = 0;
		cdf[i] = 0;
	}
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			pdf[img.at<uchar>(i, j)]++;
		}
	}

	cdf[0] = pdf[0];
	for (int i = 1; i < 256; i++) {
		cdf[i] = cdf[i - 1] + pdf[i];
		//std::cout << "cdf[" <<i <<"] = " << cdf[i] << std::endl;
	}

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			hist.at<uchar>(i, j) = (cdf[img.at<uchar>(i, j)] - cdf[0]) * 255
					/ (img.rows * img.cols);
		}
	}

}


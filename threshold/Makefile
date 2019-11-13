thresholding: thresholding.o
	g++ -std=c++11 -o thresholding thresholding.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
thresholding.o: thresholding.cpp 
	g++ -std=c++11 -c thresholding.cpp 
.PHONY: clean
clean:
	rm -f thresholding *.o

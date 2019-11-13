blurring: blurring.o
	g++ -std=c++11 -o blurring blurring.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
blurring.o: blurring.cpp 
	g++ -std=c++11 -c blurring.cpp 
.PHONY: clean
clean:
	rm -f blurring *.o

histeq: histeq.o
	g++ -std=c++11 -o histeq histeq.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
histeq.o: histeq.cpp 
	g++ -std=c++11 -c histeq.cpp 
.PHONY: clean
clean:
	rm -f histeq *.o

tomato_segmentation: tomato_segmentation.o
	g++ -std=c++11 -o tomato_segmentation tomato_segmentation.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
tomato_segmentation.o: tomato_segmentation.cpp 
	g++ -std=c++11 -c tomato_segmentation.cpp 
.PHONY: clean
clean:
	rm -f tomato_segmentation *.o

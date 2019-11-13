img_operations: img_operations.o
	g++ -std=c++11 -o img_operations img_operations.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
img_operations.o: img_operations.cpp 
	g++ -std=c++11 -c img_operations.cpp 
.PHONY: clean
clean:
	rm -f img_operations *.o

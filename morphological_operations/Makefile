morphological_operations: morphological_operations.o
	g++ -std=c++11 -o morphological_operations morphological_operations.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
morphological_operations.o: morphological_operations.cpp 
	g++ -std=c++11 -c morphological_operations.cpp 
.PHONY: clean
clean:
	rm -f morphological_operations *.o

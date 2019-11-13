edge_detection: edge_detection.o
	g++ -std=c++11 -o edge_detection edge_detection.o -l opencv_core -l opencv_imgcodecs -l opencv_imgproc -l opencv_highgui
edge_detection.o: edge_detection.cpp 
	g++ -std=c++11 -c edge_detection.cpp 
.PHONY: clean
clean:
	rm -f edge_detection *.o

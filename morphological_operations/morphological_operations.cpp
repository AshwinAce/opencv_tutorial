#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

/// Global variables
cv::Mat src, dst;

int type = 0;
int size = 0;
int iteration=1;
int operation = cv::MORPH_ERODE;
int const max_type = 2;
int const max_kernel_size = 21;
int const max_iterations= 2;
int const max_operations= 3;
/** Function Headers */
void Morph( int, void* );

/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  try{
    src = cv::imread(argv[1],1);
  }
  catch(cv::Exception& e){
    std::cout<<"Exception"<<e.what()<<std::endl;
  }

  if( !src.data ){ 
    std::cout<<"Unable to read image\n";
    return -1; 
  }

  /// Create windows
  cv::namedWindow( "Demo", cv::WINDOW_NORMAL );


  /// Create Morph Trackbar
  cv::createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Demo",
                  &type, max_type,
                  Morph );

  cv::createTrackbar( "Kernel size:\n 2n +1", "Demo",
                  &size, max_kernel_size,
                  Morph );

  cv::createTrackbar("Iterations","Demo", &iteration ,max_iterations, Morph);

  cv::createTrackbar("Morphological Operation:\n 0: Erosion \n 1: Dilation \n 2: Opening \n 3: Closing","Demo", &operation ,max_operations, Morph);

  /// Default start
  Morph( 0, 0 );


  cv::waitKey(0);
  return 0;
}

/**  @function Morph  */
void Morph( int, void* )
{
  int kernel_type,operation_type;

  if( type == 0 ){ kernel_type = cv::MORPH_RECT; }
  else if( type == 1 ){ kernel_type = cv::MORPH_CROSS; }
  else if( type == 2) { kernel_type = cv::MORPH_ELLIPSE; }

  if( operation == 0 ){ operation_type = cv::MORPH_ERODE; }
  else if( operation == 1 ){ operation_type = cv::MORPH_DILATE; }
  else if( operation == 2) { operation_type = cv::MORPH_OPEN; }
  else if( operation == 3) { operation_type = cv::MORPH_CLOSE; }
  cv::Mat kernel = cv::getStructuringElement( kernel_type,
                                       cv::Size( 2*size + 1, 2*size+1 ),
                                       cv::Point( size, size ) );

  /// Apply the Morphological operation
  cv::morphologyEx(src, dst, operation_type, kernel,
  				cv::Point(-1, -1), iteration);
  cv::imshow( "Demo", dst );
}
//inspired by https://docs.opencv.org/2.4/doc/tutorials/imgproc/opening_closing_hats/opening_closing_hats.html

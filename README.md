# opencv_tutorial
A repository that containes basic image processing functions in C++.
With very few exceptions, most of these functions take an image as a single command line argument.

Blurring is about basic filters used for noise reduction. Gaussian and spnoise are ideal images to work with here.

Edge detection is about filters used for the same. Octagon and House are the ideal images to be used here.

Histogram equalization improves the contrast of an image. histeq is the best for plain histogram equalization while house or the tomato images are best for seeing the effects of equalization on color images.

Img operations just showcases simple image operations and takes no input.

Morphological operations is about the same applied on images. I have not supplied any binary image, one should ideally  test this on a binary image and then a color image to better understand what each operation accomplishes.

Threshold shows various thresholding operations, Bookpage and Thresh are the best images to be used here.

Tomato segmentation: The name is self explanatory, I use some of the previous techniques mentioned here along with the Hough transform.

erosionanddilation.cpp is similar to Morphological operations; it uses a different function for these two operations.


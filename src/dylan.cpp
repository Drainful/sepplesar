#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

//#include "dylan.hpp"

using namespace std;
using namespace cv;

/*
 *  A contour is a boundary of an object.  Contours are closed figures.
 *  An edge is border, they are not closed. Edge is point of significant difference between 
 *  neighboring pixels.
 */
void find_contour()
{
    return;
}

int rect_region()
{
    // rectangle constructor
    // r( int x, int y, int width, int height )
    // x,y is the top-left(?) corner
    
    // blacks an image
    // Mat img;
    // img = Scalar(0);
    
    Mat img = imread("src/test.jpg");
    imshow("test", img);
    waitKey();

    Rect r( 150, 50, 150, 250 );
    
    // problem child :(
    Mat roi = img(r);

    

    Point p( 10, 9 );

    cout << (r.contains(p) ? "p is in r\n" : "p is not in r\n");

    return 0;
}

int pixel_intensity(char* file_name)
{
    Mat img;
    img = imread( file_name, IMREAD_COLOR );

    if( !img.data )
    {
        cerr << "No image data.\n";
        return -1;
    }

    int x = 0,
        y = 0;

    // Vec3b -> vector with 3 byte entries, in this case for BGR
    // note: can also be used for HSV
    // values between 0-255, a byte for each color channel
    // 3 color channels; blue green red, each a byte = 3 bytes for the Vec3b
    Vec3b intensity = img.at<Vec3b>(y,x);


    // bgr blue green red
    uchar blue = intensity.val[0]; // blue channel intensity, note blue and red channels switched!
    uchar green = intensity.val[1]; // green " "
    uchar red = intensity.val[2]; // red " "
    
    // to change an individual pixel 
    // img.at<uchar>(y,x) = 128;

    return 0;
}

int gray_save(int argc, char* argv[])
{
    if( argc != 2)
    {
        cerr << "Usage: ./dylan FILENAME\n";
        return -1;
    }

    char* imageName = argv[1];

    Mat image;
    image  = imread( imageName, IMREAD_COLOR );

    if( !image.data )
    {
        cerr << "No image data.\n";
        return -1;
    }

    Mat gray_image;
    cvtColor( image, gray_image, COLOR_BGR2GRAY );

    const char* gray_name = "src/gray.jpg";
    imwrite( gray_name, gray_image );

    namedWindow( imageName, WINDOW_AUTOSIZE );
    namedWindow( "Gray image", WINDOW_AUTOSIZE );

    imshow( imageName, image );
    imshow( "Gray image", gray_image );
    
    waitKey(0);

    return 0;
}

int main(int argc, char* argv[])
{
    rect_region(); 
    return 0;
}


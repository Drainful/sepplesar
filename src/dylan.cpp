#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
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


#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "edges.hpp"

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    // check for valid number of arguments from command line
    if(argc != 2)
    {
        cerr << "Usage: ./contours FILE_NAME\n";
        return -1;
    }

    Mat src = imread(argv[1], IMREAD_COLOR);

    if(!src.data)
    {
        cerr << "No image data. Image does not exist or incorrect name entered.\n";
        return -1;
    }

    hello_edge(src);

    return 0;
}

/*
 *  See edges.hpp for more information.
 */
void hello_edge(Mat img)
{
    imshow(window_name, img);
    waitKey(0);

    Canny(img, img, thresh, 2 * thresh);

    namedWindow(window_name);
    imshow(window_name, img);
    waitKey(0);
    return;
}

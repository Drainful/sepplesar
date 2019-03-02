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
    const int image_delay = 0 * 1000;

    // gets rid of noise
    GaussianBlur(img, img, Size(3,3), 0);

    // show original image
    imshow(window_name, img);
    waitKey(image_delay);

    // the output of canny; the edges of img
    Mat canny_output;

    // get the edges of img, save to canny_output
    Canny(img, canny_output, thresh, 2 * thresh); // does like same Mat for input and output

    // show edge image
    namedWindow(window_name);
    imshow(window_name, canny_output);
    waitKey(image_delay);
    
    // writes edges to a file
    imwrite("src/edges.png", canny_output);
    return;
}

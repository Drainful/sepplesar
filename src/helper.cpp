#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 

using namespace std;
using namespace cv;

const char* opencv_share_path = getenv("OPENCV4");

string get_cascade_path(const char* cascade_name)
{
    return string(opencv_share_path) + "haarcascades/" + cascade_name;
}


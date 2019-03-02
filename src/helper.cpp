#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 

using namespace std;
using namespace cv;

namespace environment {
    const char* opencv_share_path = getenv("OPENCV4");
}

namespace helper {
    using namespace environment;
    char* get_cascade_path(const char* cascade_name)
    {
        string(environment::opencv_share_path) + "haarcascades/" + cascade_name;
    }
}

/*
 *  Header file for edges.cpp.
 *  Prototypes and such for edges.cpp
 */

#ifndef EDGES
#define EDGES
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

///////////////////
// CONSTANTS
// 

// The hysteresis procedure threshold value
// tbh i'm not quite sure what it does
const int thresh = 40;

// The title of the window when imshow() is called 
const char* window_name = "Edgey edges";

///////////////////
// PROTOTYPES
//

/*
 *  
 */
void hello_edge(Mat image);

#endif

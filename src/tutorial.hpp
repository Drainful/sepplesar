#ifndef TUTORIAL
#define TUTORIAL

#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 

using namespace cv; 

// Function for Face Detection 
void detectAndDraw( Mat& img, CascadeClassifier& cascade,  
                CascadeClassifier& nestedCascade, double scale ); 

string cascadeName, nestedCascadeName; 

#endif

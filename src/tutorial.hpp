/*
 *
 */

#ifndef TUTORIAL
#define TUTORIAL

#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 

using namespace cv; 
using namespace std;

// Function for Face Detection 
void detectAndDraw( Mat& img, CascadeClassifier& cascade,  
                CascadeClassifier& nestedCascade, double scale ); 

// Function for face detection without nested 
void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale);

String cascadeName;
String nestedCascadeName; 

#endif

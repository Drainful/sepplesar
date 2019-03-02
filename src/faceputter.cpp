
// CPP program to detects face in a video 
  
// Include required header files from OpenCV directory 
#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include <iostream> 
  
using namespace std; 
using namespace cv; 
  
// Function for Face Detection 
void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale ); 
string cascadeName, nestedCascadeName; 
  
int main( int argc, const char** argv ) 
{ 
    // VideoCapture class for playing video for which faces to be detected 
    VideoCapture capture;  
    Mat frame, image; 
  
    // PreDefined trained XML classifiers with facial features 
    CascadeClassifier cascade;  
    double scale=1; 
  
                    
    // Change path before execution  
    cascade.load( "/usr/share/opencv/haarcascades/haarcascade_frontalface_default.xml" ) ;  
  
    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video 
    capture.open(0);  
    if( capture.isOpened() ) 
    { 
        // Capture frames from video and detect faces 
        cout << "Face Detection Started...." << endl; 
        while(1) 
        { 
            capture >> frame; 
            if( frame.empty() ) 
                break;
            Mat frame1 = frame.clone(); 
            detectAndDraw( frame1, cascade, scale );  
            char c = (char)waitKey(10); 
          
            // Press q to exit from window 
            if( c == 27 || c == 'q' || c == 'Q' )  
                break; 
        } 
    } 
    else
        cout<<"Could not Open Camera"; 
    return 0; 
} 
  
void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale) 
{ 
    vector<Rect> faces, faces2; 
    Mat gray, smallImg;

    Mat laughing;
    Mat mod_laugh;
    laughing = imread("resources/logo.jpg", IMREAD_COLOR);
  
    cvtColor( img, gray, COLOR_BGR2GRAY ); // Convert to Gray Scale 
    double fx = 1 / scale; 
  
    // Resize the Grayscale Image  
    resize( gray, smallImg, Size(), fx, fx, INTER_AREA );  
    equalizeHist( smallImg, smallImg ); 
    // Detect faces of different sizes using cascade classifier  
    cascade.detectMultiScale( smallImg, faces, 1.1,  
                            2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) ); 
    // Draw circles around the faces 
    for ( size_t i = 0; i < faces.size(); i++ ) 
    { 
        Rect r = faces[i];
        //Point center; 
        Scalar color = Scalar(255, 0, 0); // Color for Drawing tool 
        //int radius; 
        
        double aspect_ratio = (double)r.width/r.height; 
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 ) 
        { 
            resize(laughing, mod_laugh, r.size(), 1, 1, INTER_LINEAR);
            //mod_laugh.copyTo(img(Rect(r.tl(), r.size())));
            //rectangle(img, Point(r.x, r.y), Point(r.x+r.width, r.y+r.height), color, 3, 8, 0);
            mod_laugh.copyTo(img(Rect(r.size(), mod_laugh.size())));
        } 
        else
            rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)), 
                    cvPoint(cvRound((r.x + r.width-1)*scale),  
                    cvRound((r.y + r.height-1)*scale)), color, 3, 8, 0); 
    } 
  
    // Show Processed Image with detected faces 
    imshow( "Face Detection", img );  
} 


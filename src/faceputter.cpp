
// CPP program to detects face in a video 
  
// Include required header files from OpenCV directory 
#include "opencv2/objdetect/objdetect.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include <iostream> 

#include "tutorial.hpp"

using namespace std; 
using namespace cv; 


const char* opencv_share_path = getenv("OPENCV4");

string get_cascade_path(const char* cascade_name)
{
    cout << "TEST:" << string(opencv_share_path) << endl;
    return string(opencv_share_path) + "haarcascades/" + cascade_name;
}
  
int main( int argc, const char** argv ) 
{ 
    // VideoCapture class for playing video for which faces to be detected 
    VideoCapture capture;  
    Mat frame, image; 
  
    // PreDefined trained XML classifiers with facial features 
    CascadeClassifier cascade;  
    double scale=1; 
                    
    // Change path before execution  
    cascade.load(get_cascade_path("haarcascade_frontalface_default.xml"));  
  
    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video 
    capture.open(0);  
    if( capture.isOpened() ) 
    { 
        // Capture frames from video and detect faces 
        cout << "Face Detection Started...." << endl; 
        int frame_num = 0;
        Mat frame1;
        while(1) 
        { 
            frame_num = (frame_num +1)%50;
            capture >> frame; 
            
            if( frame.empty() ) 
                break;

            if( frame_num == 0)
            {
                imshow("Face paste", frame);
                continue;
            }

            GaussianBlur(frame, frame1, Size(3,3), 0);
            //frame1 = frame.clone(); 
            //resize(frame, frame1, frame.size(), 1, 1, INTER_LINEAR);
            detectAndDraw( frame1, cascade, scale );  
            //imshow("", frame1);
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
    Mat gray, smallImg, mask_img, mod_mask;

    const string mask_file_name = "resources/haha.png";
    mask_img = imread(mask_file_name, IMREAD_UNCHANGED);
  
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
            resize(mask_img, mod_mask, r.size(), scale, scale, INTER_LINEAR);
            mod_mask.copyTo(img(Rect(r.tl(), r.size())));
            //rectangle(img, Point(r.x, r.y), Point(r.x+r.width, r.y+r.height), color, 3, 8, 0);
        } 
        else
            rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)), 
                    cvPoint(cvRound((r.x + r.width-1)*scale),  
                    cvRound((r.y + r.height-1)*scale)), color, 3, 8, 0); 
    } 
  
    // Show Processed Image with detected faces 
    imshow( "Face paste", img );  
} 


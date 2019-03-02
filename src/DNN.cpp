/*
 *
 */
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/objdetect.hpp"
#include <iostream>

using namespace std;
using namespace cv;
using namespace dnn;

int main(int argc, char** argv)
{
    const string caffeConfigFile = "./deploy.prototxt";
    const string caffeWeightFile = "./res10_300x300_ssd_iter_140000_fp16.caffemodel";
 
    const string tensorflowConfigFile = "./opencv_face_detector.pbtxt";
    const string tensorflowWeightFile = "./opencv_face_detector_uint8.pb";
 
    #ifdef CAFFE
    Net net = cv::dnn::readNetFromCaffe(caffeConfigFile, caffeWeightFile);
    #else
    Net net = cv::dnn::readNetFromTensorflow(tensorflowWeightFile, tensorflowConfigFile);
    #endif

}

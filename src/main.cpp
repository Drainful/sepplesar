#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Hello, World!\n";
    const char* grades = " ABCDF";
    cout << grades[argc];
    return 0;
}

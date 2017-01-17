#ifndef OPENCVMETHODS_H
#define OPENCVMETHODS_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


Mat gammaCorrection(Mat &mat, double gamma);
Mat changeBrightness(Mat &mat, int brightness);
Mat changeContrast(Mat &mat, double contrast);
Mat calculateHistogram(Mat &mat);
Mat equalizeHistogram(Mat &mat);
Mat drawAnImageOverAnother(Mat &src, int size, int color);
Mat fastCompleteCorrection(Mat &mat, double gamma, int brightness, double contrast);
Mat createMask(int size);
Mat cropMatrix(Mat &src, int xM, int yM, int width, int height);
Mat displayArea(Mat &src, int xM, int yM, int width, int height);

#endif // OPENCVMETHODS_H

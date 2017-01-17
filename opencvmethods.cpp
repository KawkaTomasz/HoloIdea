#include "opencvmethods.h"

Mat gammaCorrection(Mat &mat, double gamma) {
  Mat gammaCorrectedMat = Mat::zeros(mat.size(), mat.type());

  //gamma value [0.1-2.0]
  for (int y = 0; y < mat.rows; ++y) {
    for (int x = 0; x < mat.cols; ++x) {
      double intensity = mat.at<uchar>(y, x);
      gammaCorrectedMat.at<uchar>(y, x) = saturate_cast<uchar>(255*pow((intensity/255.0),gamma));
    }
  }
  return gammaCorrectedMat;
}

Mat changeBrightness(Mat &mat, int brightness) {
  Mat brightnessChangedMat = Mat::zeros(mat.size(), mat.type());

  ///Operacja na obrazku(i,j) = obrazek(i,j) + brightness
  for (int y = 0; y < mat.rows; ++y) {
    for (int x = 0; x < mat.cols; ++x) {
      brightnessChangedMat.at<uchar>(y, x) = saturate_cast<uchar>((mat.at<uchar>(y, x)) + brightness);
    }
  }
  return brightnessChangedMat;
}

Mat changeContrast(Mat &mat, double contrast) {
  Mat contrastChangedMat = Mat::zeros(mat.size(), mat.type());

  ///Operacja na obrazku(i,j) = contrast*obrazek(i,j)
  for (int y = 0; y < mat.rows; ++y) {
    for (int x = 0; x < mat.cols; ++x) {
      contrastChangedMat.at<uchar>(y, x) = saturate_cast<uchar>(contrast*(mat.at<uchar>(y, x)));
    }
  }
  return contrastChangedMat;
}

Mat fastCompleteCorrection(Mat &mat, double gamma, int brightness, double contrast) {
     Mat correctedMat = Mat::zeros(mat.size(), mat.type());
     for (int y = 0; y < mat.rows; ++y) {
       for (int x = 0; x < mat.cols; ++x) {
         double intensity = mat.at<uchar>(y, x);
         /// changeContrast - contrast*image(y,x)
         /// changeBrightness - image(y,x) + brightness
         /// gammaCorrection - 255*pow((intensity/255.0),gamma)
         correctedMat.at<uchar>(y, x) = saturate_cast<uchar>(255*pow((contrast*(intensity+brightness)/255.0),gamma));
       }
     }
    return correctedMat;
}

Mat calculateHistogram(Mat &mat) {
    // Set histogram bins count
    int bins = 256;
    int histSize[] = {bins};
    // Set ranges for histogram bins
    float lranges[] = {0, 256};
    const float* ranges[] = {lranges};
    // create matrix for histogram
    cv::Mat hist;
    int channels[] = {0};
    int const hist_height = 256;
    // create matrix for histogram visualization
    Mat histImage(hist_height, bins, CV_8U, Scalar(255, 255, 255));
    /// Calculate the histogram
    cv::calcHist(&mat, 1, channels, cv::Mat(), hist, 1, histSize, ranges, true, false);
    double max_val=0;
    minMaxLoc(hist, 0, &max_val);
    /// Drawing histogram
    for(int b = 0; b < bins; b++) {
        float const binVal = hist.at<float>(b);
        int   const height = cvRound(binVal*hist_height/max_val);
        cv::line
            ( histImage
            , cv::Point(b, hist_height-height), cv::Point(b, hist_height)
            , cv::Scalar::all(0)
            );
    }
    return histImage;
}

Mat equalizeHistogram(Mat &mat) {
  Mat equalizedMat = Mat::zeros(mat.size(), mat.type());
  equalizeHist(mat, equalizedMat);
  return equalizedMat;
}

Mat createMask(int size) {
    Mat mask(size, size, CV_8UC1, Scalar(0));
    return mask;
}

Mat drawAnImageOverAnother(Mat &src, int size, int color) {
    // Create destination mat which will include the orignal one
    Mat dst(size, size, CV_8UC1, Scalar(color));
    // These variables are used to calculate the range
    // in the center of dst mat for source matrix.
    int row_start = dst.rows / 2 - src.rows / 2;
    int row_end = row_start + src.rows;
    int col_start = dst.cols / 2 - src.cols / 2;
    int col_end = col_start + src.cols;

    src.copyTo(dst.rowRange(row_start,row_end).colRange(col_start,col_end));
    return dst;
}

Mat cropMatrix(Mat &src ,int xM, int yM, int width, int height) {
    Rect croppedRectangle = Rect(xM, yM, width, height);
    Mat croppedMat = src(croppedRectangle);
    return croppedMat;
}

Mat displayArea(Mat &src, int xM, int yM, int width, int height) {
    Rect croppedRectangle = Rect(xM, yM, width, height);
    rectangle(src,croppedRectangle,Scalar(0),2);
    return src;
}

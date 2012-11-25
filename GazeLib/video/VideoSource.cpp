/*
 * VideoSource.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: krigu
 */

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "VideoSource.hpp"

using namespace std;
using namespace cv;

VideoSource::VideoSource(string videoPath) {
	// TODO: proper implemented?
	videoCapture = VideoCapture(videoPath);
}

VideoSource::~VideoSource() {
	videoCapture.release();
}


bool VideoSource::nextGrayFrame(cv::Mat& frame) {

	// Check if capture is open
	if (!videoCapture.isOpened())
		return false;

	// Check if there are more frames
	if (!videoCapture.read(frame))
		return false;

	 // Check for invalid input
	if (!frame.data)
		return false;

	// Convert to grayscale
	cvtColor(frame, frame, CV_BGR2GRAY);

	return true;
}

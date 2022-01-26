/*
 * gipOpenCV.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Onur Demir
 */

#ifndef SRC_GIPOPENCV_H_
#define SRC_GIPOPENCV_H_

#include "gBasePlugin.h"

#include "gImage.h"
#include "opencv2/opencv.hpp"


class gipOpenCV : public gBasePlugin {
public:
	gipOpenCV();
	virtual ~gipOpenCV();

	void makeGray(gImage* image);
	void makeCanny(gImage* image, float threshold1, float threshold2);
	std::vector<cv::Rect> objectDetection(gImage* image, std::string xmlFilePath, float scaleFactor = 1.1f, int minNeighbors = 3);
	std::vector<cv::Rect> faceDetection(gImage* image);
	void objectsDraw(std::vector<cv::Rect> objects,gImage* image, std::string objectName = "", float fontSize = 1.0f, cv::Scalar color = cv::Scalar(0, 255, 0), int thickness = 1, float scaleFactor = 1.1f, int minNeighbors = 3);
	void contourDetection(gImage* image, int thickness = 1, int thresh = 150, int maxValue = 255, cv::Scalar color = cv::Scalar(0, 255, 0));

	void updateImagefromCam(gImage* image);

	void setMatData(gImage* image);
	void setCam(int cam = 0);
private:
	cv::Mat mat;
	cv::VideoCapture cap;
};

#endif /* SRC_GIPOPENCV_H_ */

/*
 * gGuiOpenCVCamera.h
 *
 *  Created on: 29 Aðu 2023
 *      Author: arda kirik
 */
#include "gipOpenCV.h"
#include "opencv2/opencv.hpp"


#ifndef GGUIOPENCVCAMERA_H_
#define GGUIOPENCVCAMERA_H_

class gGuiOpenCVCamera: public gGUIControl {
public:
	gGuiOpenCVCamera();
	virtual ~gGuiOpenCVCamera();
	void rectDraw();
	int getWidth();
	int getHeight();
	void draw();

private:
	gipOpenCV cv;
	gImage cameraImage;
	cv::VideoCapture cap;
};

#endif /* GGUIOPENCVCAMERA_H_ */

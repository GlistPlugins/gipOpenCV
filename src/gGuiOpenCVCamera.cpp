/*
 * gGuiOpenCVCamera.cpp
 *
 *  Created on: 29 Aðu 2023
 *      Author: arda kirik
 */

#include "gGuiOpenCVCamera.h"

gGuiOpenCVCamera::gGuiOpenCVCamera() {
	cv.setCam();
}

gGuiOpenCVCamera::~gGuiOpenCVCamera() {

}

int gGuiOpenCVCamera::getWidth() {
	return renderer->getWidth();

}

int gGuiOpenCVCamera::getHeight() {
	return renderer->getHeight();

}

void gGuiOpenCVCamera::rectDraw() {
	cv.updateImagefromCam(&cameraImage);
 	//gLogi("camera") << "w:" <<  cameraImage.getWidth() << " h:" << cameraImage.getHeight();
	cv::Mat mat = cv::Mat(cameraImage.getWidth(), cameraImage.getHeight(), CV_8UC(cameraImage.getComponentNum()), cameraImage.getImageData());
    gDrawRectangle((getWidth() - mat.cols) / 2 , (getHeight() - mat.rows) / 2, mat.rows + 5, mat.cols + 5, 0);
    cameraImage.setImageData(cameraImage.getImageData(), cameraImage.getWidth(), cameraImage.getHeight(), cameraImage.getComponentNum());
    cameraImage.useData();
    cameraImage.draw((getWidth() - mat.cols) / 2, (getHeight() - mat.rows) / 2);

}

void gGuiOpenCVCamera::draw() {
    rectDraw();
}

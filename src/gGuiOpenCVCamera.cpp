/*
 * gGuiOpenCVCamera.cpp
 *
 *  Created on: 29 Aug 2023
 *      Author: arda kirik
 *      Edited by Noyan Culum
 */

#include "gGuiOpenCVCamera.h"

gGuiOpenCVCamera::gGuiOpenCVCamera() {
	cv.setCam();
}

gGuiOpenCVCamera::~gGuiOpenCVCamera() {

}

gImage* gGuiOpenCVCamera::getImage() {
	return &cameraimage;
}

void gGuiOpenCVCamera::update() {
	cv.updateImagefromCam(&cameraimage);
}

void gGuiOpenCVCamera::draw() {
    cameraimage.draw(0, 0, width, height);
}

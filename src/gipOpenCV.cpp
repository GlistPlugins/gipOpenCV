/*
 * gipOpenCV.cpp
 *
 *  Created on: 13 Aðu 2021
 *      Author: berka
 */

#include "gipOpenCV.h"

gipOpenCV::gipOpenCV() {
}

gipOpenCV::~gipOpenCV() {
}

void gipOpenCV::loadOpenCVImage(std::string fullPath) {
	fullpath = fullPath;
	sourceimage = cv::imread(fullpath.c_str(), 1);
	if (sourceimage.empty())
	 {
	  gLogi("gipOpenCV") << "Could not open or find the image";
	  exit(0);
	 }
}

void gipOpenCV::contrastStretch() {

}

void gipOpenCV::convertToRange() {

}

void gipOpenCV::erode() {

}

void gipOpenCV::dilate() {

}

void gipOpenCV::blur() {

}

void gipOpenCV::blurGaussian() {

}

void gipOpenCV::invert() {
	cv::namedWindow("Binary Image", 1);
	cv::namedWindow("Inverted Binary Image", 1);
	cv::cvtColor(sourceimage, grayscaleimage, COLOR_BGR2GRAY);
	cv::threshold(grayscaleimage, binaryimage, 100, 255, THRESH_BINARY);
	bitwise_not(binaryimage, invertedbinaryimage);
	imshow("Binary Image", binaryimage);
	imshow("Inverted Binary Image", invertedbinaryimage);
}


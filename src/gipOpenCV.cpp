/*
 * gipOpenCV.cpp
 *
 *  Created on: Jan 10, 2022
 *      Author: Onur Demir
 */

#include "gipOpenCV.h"

gipOpenCV::gipOpenCV() {
}

gipOpenCV::~gipOpenCV() {

}

void gipOpenCV::makeGray(gImage* image) {
	setMatData(image);
	cvtColor(mat, mat, COLOR_BGRA2GRAY);
	cvtColor(mat, mat, COLOR_GRAY2RGBA);
	image->setImageData(mat.data, mat.cols, mat.rows, 4);
}

void gipOpenCV::makeCanny(gImage* image, float threshold1, float threshold2) {
	setMatData(image);
	cvtColor(mat, mat, COLOR_BGRA2GRAY);
	Canny(mat, mat, threshold1, threshold2);
	cvtColor(mat, mat, COLOR_BGRA2RGBA);
	image->setImageData(mat.data, mat.cols, mat.rows, 4);
}

std::vector<Rect> gipOpenCV::objectDetection(gImage* image, std::string xmlFilePath, float scaleFactor, int minNeighbors) {
	setMatData(image);
	CascadeClassifier cascade;
	cascade.load(xmlFilePath);

	if(cascade.empty()) {
		gLogi("Xml file not found");
	}

	std::vector<Rect> objects;
	cascade.detectMultiScale(mat, objects, scaleFactor, minNeighbors);
	return objects;
}

void gipOpenCV::objectsDraw(std::vector<Rect> objects,gImage* image, std::string xmlFilePath, Scalar color, int thickness, float scaleFactor, int minNeighbors) {
	for(int i = 0; i < objects.size(); i++) {
		gLogi("GameCanvas") << "i: " << gToStr(i);
		rectangle(mat, objects[i].tl(), objects[i].br(), color, thickness);
	}
	cvtColor(mat, mat, COLOR_BGRA2RGBA);
	image->setImageData(mat.data, mat.cols, mat.rows, 4);
}

void gipOpenCV::contourDetection(gImage* image, int thickness, int thresh, int maxValue, Scalar color) {
	setMatData(image);
	cvtColor(mat, mat, COLOR_BGRA2BGR);
	Mat mat_copy = mat.clone();
	cvtColor(mat, mat, COLOR_BGR2GRAY);
	threshold(mat, mat, thresh, maxValue, THRESH_BINARY);
	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	findContours(mat, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	drawContours(mat_copy, contours, -1, color, thickness);
	cvtColor(mat_copy, mat_copy, COLOR_BGR2RGBA);
	image->setImageData(mat_copy.data, mat_copy.cols, mat_copy.rows, 4);
}

void gipOpenCV::updateImagefromCam(gImage* image) {
	cap.read(mat);
	cvtColor(mat, mat, COLOR_BGR2RGBA);
	image->setImageData(mat.data, mat.cols, mat.rows, 4);
}

void gipOpenCV::setMatData(gImage* image) {
	mat = imread(image->getFullPath(), IMREAD_UNCHANGED);
}

void gipOpenCV::setCam(int cam) {
	cap = VideoCapture(cam);
}

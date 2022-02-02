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
	cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	cv::cvtColor(mat, mat, cv::COLOR_GRAY2RGB);
	gLogi("gipOpenCV") << gToStr(image->getComponentNum() + 1);
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
}

void gipOpenCV::makeCanny(gImage* image, float threshold1, float threshold2) {
	setMatData(image);
	cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	Canny(mat, mat, threshold1, threshold2);
	cv::cvtColor(mat, mat, cv::COLOR_BGRA2RGB);
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
}

std::vector<cv::Rect> gipOpenCV::objectDetection(gImage* image, std::string xmlFilePath, float scaleFactor, int minNeighbors) {
	setMatData(image);
	cv::CascadeClassifier cascade;
	cascade.load(xmlFilePath);

	if(cascade.empty()) {
		gLogi("Xml file not found");
	}

	std::vector<cv::Rect> objects;
	cascade.detectMultiScale(mat, objects, scaleFactor, minNeighbors);
	return objects;
}

std::vector<cv::Rect> gipOpenCV::faceDetection(gImage* image) {
	return objectDetection(image, gGetFilesDir() + "haarcascade_frontalcatface.xml");
}

void gipOpenCV::objectsDraw(std::vector<cv::Rect> objects,gImage* image, std::string objectName, float fontSize, cv::Scalar color, int thickness, float scaleFactor, int minNeighbors) {
	if(!objects.empty()) {
		for(int i = 0; i < objects.size(); i++) {
			cv::rectangle(mat, objects[i].tl(), objects[i].br(), color, thickness);
			cv::putText(mat, objectName, objects[i].tl(), 0, fontSize, color, thickness);
		}
		cv::cvtColor(mat, mat, image->getComponentNum() + 1);
		image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
		return;
	}
	cv::cvtColor(mat, mat, image->getComponentNum() + 1);
	gLogi("gipOpenCV") << "List is Empty";
}

void gipOpenCV::contourDetection(gImage* image, int thickness, int thresh, int maxValue, cv::Scalar color) {
	setMatData(image);
	cv::cvtColor(mat, mat, cv::COLOR_BGRA2BGR);
	cv::Mat mat_copy = mat.clone();
	cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	cv::threshold(mat, mat, thresh, maxValue, cv::THRESH_BINARY);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(mat, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
	drawContours(mat_copy, contours, -1, color, thickness);
	cv::cvtColor(mat_copy, mat_copy, cv::COLOR_BGR2RGBA);
	image->setImageData(mat_copy.data, mat_copy.cols, mat_copy.rows, image->getComponentNum());
}
std::string gipOpenCV::readTextFromImage(gImage* image) {
	gLogi("gipOpenCV") << "Calisti";
	setMatData(image);

//	TODO: When Tesseract Libary fixed, these comment lines will be removed.

//	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
//	api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
//	api->SetPageSegMode(tesseract::PSM_AUTO);
//	api->SetImage(mat.data, mat.cols, mat.rows, image->getComponentNum(), mat.step);
//	std::string outext = std::string(api->GetUTF8Text());
//	api->End();

	return "";
}

void gipOpenCV::updateImagefromCam(gImage* image) {
	cap.read(mat);
//	cv::cvtColor(mat, mat, image->getComponentNum() + 1);
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
}

void gipOpenCV::updateImagefromVideo(gImage* image) {
	cap.read(mat);
	gLogi("gipOpenCV") << gToStr(mat.data).size();
//	cv::cvtColor(mat, mat, 4);
//	image->clearData();
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
	image->useData();
}

void gipOpenCV::setMatData(gImage* image) {
	mat = cv::Mat(image->getHeight(), image->getWidth(), CV_8UC(image->getComponentNum()), image->getImageData());
	cv::cvtColor(mat, mat, image->getComponentNum() + 1);
}

void gipOpenCV::setCam(int cam) {
	cap = cv::VideoCapture(cam);
}

void gipOpenCV::setVideo(std::string videopath) {
	cap = cv::VideoCapture(gGetVideosDir() + videopath);
}

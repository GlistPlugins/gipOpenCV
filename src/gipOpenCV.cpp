/*
 * gipOpenCV.cpp
 *
 *  Created on: Jan 10, 2022
 *      Author: Onur Demir
 */

#include "gipOpenCV.h"

gipOpenCV::gipOpenCV() {
	tessdatapath = gGetFilesDir() + "tessdata";
	languages[0] = "eng";
	languages[1] = "fra";
	languages[2] = "spa";
	languages[3] = "ita";
	languages[4] = "deu";
	languages[5] = "por";
	languages[6] = "tur";
	langno = 0;
}

gipOpenCV::~gipOpenCV() {

}

void gipOpenCV::makeGray(gImage* image) {
	setMatData(image);
	cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	cv::cvtColor(mat, mat, image->getComponentNum() + 5);
//	gLogi("gipOpenCV") << gToStr(image->getComponentNum() + 1);
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
}

void gipOpenCV::makeCanny(gImage* image, float threshold1, float threshold2) {
	setMatData(image);
	if(image->getComponentNum() == 4) cv::cvtColor(mat, mat, cv::COLOR_BGRA2GRAY);
	else cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	Canny(mat, mat, threshold1, threshold2);
	if(image->getComponentNum() == 4) cv::cvtColor(mat, mat, cv::COLOR_BGRA2RGBA);
	else cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
	image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
}

std::vector<cv::Rect> gipOpenCV::objectDetection(gImage* image, std::string xmlFilePath, bool isVideo, float scaleFactor, int minNeighbors) {
	if(!isVideo) setMatData(image);
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

void gipOpenCV::objectsDraw(std::vector<cv::Rect> objects,gImage* image, std::string objectName, float fontSize, cv::Scalar color, int thickness) {
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
//	gLogi("gipOpenCV") << "List is Empty";
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
    setMatData(image);
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    ocr->SetVariable("debug_file", "/dev/null");
    ocr->Init(getTessDataPath(), languages[langno], tesseract::OEM_LSTM_ONLY);
    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->SetImage(mat.data, mat.cols, mat.rows, 3, mat.step);
    std::string outText = std::string(ocr->GetUTF8Text());
    ocr->End();
    return outText;
}

std::vector<cv::Rect> gipOpenCV::carPlateDetection(gImage* image) {
	return objectDetection(image, gGetFilesDir() + "haarcascade_russian_plate_number.xml");
}

void gipOpenCV::cropMat(std::vector<cv::Rect> objects) {
	if(!objects.empty() && objects.size() == 1) {
		cv::Mat croppedmat = originalmat(cv::Range(objects[0].tl().y, objects[0].br().y), cv::Range(objects[0].tl().x, objects[0].br().x));
//		cv::cvtColor(croppedmat, croppedmat, image->getComponentNum() + 1);
		cv::imshow("Crop", croppedmat);
//		cv::cvtColor(croppedmat, croppedmat, image->getComponentNum() + 1);
//		image->setImageData(croppedmat.data, croppedmat.cols, croppedmat.rows, image->getComponentNum());
	}
}

void gipOpenCV::updateImagefromCam(gImage* image) {
	cap.read(mat);
	cv::cvtColor(mat, mat, 4);
//	gLogi("gipOpenCV") < "mat cols:" << mat.cols << ", rows:" << mat.rows << ", comp:" << mat
	image->setImageData(mat.data, mat.cols, mat.rows, 3);
	image->useData();
}

void gipOpenCV::updateImagefromVideo(gImage* image) {
	cap.read(mat);
//	gLogi("gipOpenCV") << gToStr(mat.data).size();
	cv::cvtColor(mat, mat, 4);
//	image->clearData();
	image->setImageData(mat.data, mat.cols, mat.rows, 3);
	image->useData();
}

void gipOpenCV::setMatData(gImage* image) {
	mat = cv::Mat(image->getHeight(), image->getWidth(), CV_8UC(image->getComponentNum()), image->getImageData());
	cv::cvtColor(mat, mat, image->getComponentNum());
	originalmat = mat.clone();
}

void gipOpenCV::setCam(int cam) {
	cap = cv::VideoCapture(cam);
}

void gipOpenCV::setVideo(std::string videopath) {
	cap = cv::VideoCapture(gGetVideosDir() + videopath);
}

char* gipOpenCV::getTessDataPath() {
	char* filesdir = const_cast<char*>(tessdatapath.c_str());
	return filesdir;
}

void gipOpenCV::setDataLanguage(int languageNo) {
	langno = languageNo;
}

std::string gipOpenCV::readTextFromImage(cv::Mat m) {
	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
	ocr->SetVariable("debug_file", "/dev/null");
	ocr->Init(getTessDataPath(), languages[langno], tesseract::OEM_LSTM_ONLY);
	ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->SetImage(m.data, m.cols, m.rows, 3, m.step);
    std::string outText = std::string(ocr->GetUTF8Text());
    ocr->End();
    return outText;
}

cv::Mat gipOpenCV::getMat() {
	return mat;
}

cv::Mat gipOpenCV::getOriginalMat() {
	return originalmat;
}

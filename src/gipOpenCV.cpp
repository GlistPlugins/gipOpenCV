/*
 * gipOpenCV.cpp
 *
 *  Created on: Jan 10, 2022
 *      Author: Onur Demir
 */

#include "gipOpenCV.h"

gipOpenCV::gipOpenCV() {
	tessdatapath = gGetFilesDir() + "tessdata";
	languages[0] = (char*)"eng";
	languages[1] = (char*)"fra";
	languages[2] = (char*)"spa";
	languages[3] = (char*)"ita";
	languages[4] = (char*)"deu";
	languages[5] = (char*)"por";
	languages[6] = (char*)"tur";
	langno = 0;
}

gipOpenCV::~gipOpenCV() {

}

void gipOpenCV::makeGray(gImage* image) {
	setMatData(image);
	cv::cvtColor(mat, mat, cv::COLOR_BGR2GRAY);
	cv::cvtColor(mat, mat, image->getComponentNum() + 5);
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

void gipOpenCV::objectsDraw(std::vector<cv::Rect> objects, gImage* image, std::string objectName, float fontSize, cv::Scalar color, int thickness) {
	setMatData(image);
	if(!objects.empty()) {
		for(size_t i = 0; i < objects.size(); i++) {
			rectangle(mat, objects[i].tl(), objects[i].br(), color, thickness);
			cv::putText(mat, objectName, objects[i].tl(), 0, fontSize, color, thickness);
		}
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGBA);
		image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
		return;
	}
	cv::cvtColor(mat, mat, cv::COLOR_BGR2RGBA);
}

void gipOpenCV::contourDetection(gImage* image, int thickness, int thresh, int maxValue, cv::Scalar color) {
	setMatData(image);
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
	if(!image) return "";
	setMatData(image);
	return readTextFromImage(mat);
}

std::string gipOpenCV::readTextFromImage(cv::Mat m) {
	if(m.empty()) return "";

	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
#if defined(WIN32)
	ocr->SetVariable("debug_file", "NUL");
#else
	ocr->SetVariable("debug_file", "/dev/null");
#endif

	// Collect candidate directories for tessdata
	std::vector<std::string> candidate_paths;
	candidate_paths.push_back(getTessDataPath());
	candidate_paths.push_back(gGetFilesDir() + "tessdata");
	candidate_paths.push_back(gGetFilesDir());
	candidate_paths.push_back(gGetAssetsDir() + "files/tessdata");
	candidate_paths.push_back(gGetAssetsDir() + "files");
	candidate_paths.push_back(gGetAssetsDir() + "tessdata");
	candidate_paths.push_back("assets/files/tessdata");
	candidate_paths.push_back("assets/files");
	candidate_paths.push_back("files/tessdata");
	candidate_paths.push_back("/data/data/dev.glist.glistapp/files/files/tessdata");
	candidate_paths.push_back("/data/data/dev.glist.glistapp/files/files");
	candidate_paths.push_back("/data/data/dev.glist.glistapp/files/tessdata");
	candidate_paths.push_back("/data/data/dev.glist.glistapp/files");
	candidate_paths.push_back("/data/user/0/dev.glist.glistapp/files/files/tessdata");
	candidate_paths.push_back("/data/user/0/dev.glist.glistapp/files/files");
	candidate_paths.push_back("/data/user/0/dev.glist.glistapp/files/tessdata");
	candidate_paths.push_back("/data/user/0/dev.glist.glistapp/files");

	bool inited = false;
	const char* lang = (langno >= 0 && langno < 7) ? languages[langno] : "eng";

	for(const auto& path : candidate_paths) {
		if(path.empty()) continue;
		int res = ocr->Init(path.c_str(), lang, tesseract::OEM_LSTM_ONLY);
		if(res == 0) {
			inited = true;
			break;
		}
	}

	if(!inited) {
		for(const auto& path : candidate_paths) {
			if(path.empty()) continue;
			int res = ocr->Init(path.c_str(), lang, tesseract::OEM_DEFAULT);
			if(res == 0) {
				inited = true;
				break;
			}
		}
	}

	if(!inited) {
		delete ocr;
		return "";
	}

	// Convert to Grayscale for highest OCR recognition accuracy
	cv::Mat gray;
	if(m.channels() == 4) {
		cv::cvtColor(m, gray, cv::COLOR_RGBA2GRAY);
	} else if(m.channels() == 3) {
		cv::cvtColor(m, gray, cv::COLOR_RGB2GRAY);
	} else {
		gray = m.clone();
	}

	ocr->SetPageSegMode(tesseract::PSM_AUTO);
	ocr->SetImage(gray.data, gray.cols, gray.rows, 1, gray.step);
	char* utf8Text = ocr->GetUTF8Text();
	std::string outText = utf8Text ? std::string(utf8Text) : "";
	if(utf8Text) delete[] utf8Text;
	ocr->End();
	delete ocr;

	return outText;
}

std::vector<cv::Rect> gipOpenCV::carPlateDetection(gImage* image) {
	return objectDetection(image, gGetFilesDir() + "haarcascade_russian_plate_number.xml");
}

void gipOpenCV::cropMat(std::vector<cv::Rect> objects) {
#if !defined(ANDROID) && !defined(__ANDROID__)
	if(!objects.empty() && objects.size() == 1) {
		cv::Mat croppedmat = originalmat(cv::Range(objects[0].tl().y, objects[0].br().y), cv::Range(objects[0].tl().x, objects[0].br().x));
		cv::imshow("Crop", croppedmat);
	}
#endif
}

void gipOpenCV::updateImagefromCam(gImage* image) {
	if(!image || !cap.isOpened()) return;

	if(cap.read(mat)) {
		if(!mat.empty()) {
			cv::cvtColor(mat, mat, cv::COLOR_BGR2RGBA);
			image->setImageData(mat.data, mat.cols, mat.rows, 4);
			image->useData();
		}
	}
}

void gipOpenCV::updateImagefromVideo(gImage* image) {
	if(!image || !cap.isOpened()) return;
	if(cap.read(mat)) {
		if(!mat.empty()) {
			cv::cvtColor(mat, mat, cv::COLOR_BGR2RGBA);
			image->setImageData(mat.data, mat.cols, mat.rows, image->getComponentNum());
		}
	}
}

void gipOpenCV::setMatData(gImage* image) {
	if(!image || !image->getImageData() || image->getWidth() <= 0 || image->getHeight() <= 0) return;
	if(image->getComponentNum() == 4) {
		mat = cv::Mat(image->getHeight(), image->getWidth(), CV_8UC4, image->getImageData());
	} else {
		mat = cv::Mat(image->getHeight(), image->getWidth(), CV_8UC3, image->getImageData());
	}
	originalmat = mat.clone();
}

void gipOpenCV::setCam(int camNo) {
#if !defined(ANDROID) && !defined(__ANDROID__)
	if(cap.isOpened()) {
		cap.release();
	}
#ifdef _WIN32
	cap.open(camNo, cv::CAP_DSHOW);
	if(!cap.isOpened()) {
		cap.open(camNo, cv::CAP_ANY);
	}
#else
	cap.open(camNo);
#endif
#endif
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

cv::Mat gipOpenCV::getMat() {
	return mat;
}

cv::Mat gipOpenCV::getOriginalMat() {
	return originalmat;
}

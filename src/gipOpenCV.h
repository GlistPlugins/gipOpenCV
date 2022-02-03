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
#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "opencv2/opencv.hpp"

/**
 * Enables the processing of uploaded image or video.
 */
class gipOpenCV : public gBasePlugin {
public:
	gipOpenCV();
	virtual ~gipOpenCV();

	/**
	 * Makes the imported image  gray.
	 *
	 * @param image the image you want to change.
	 */
	void makeGray(gImage* image);

	/**
	 * Makes the imported image binary.
	 *
	 * @param image the image you want to change.
	 * @param threshold1 first threshold for the hysteresis procedure.
	 * @param threshold2 second threshold for the hysteresis procedure.
	 */
	void makeCanny(gImage* image, float threshold1, float threshold2);

	/**
	 * Finds the locations of objects based on the XML file put in.
	 *
	 * @param image an image where objects are detected.
	 * @param scaleFactor Parameter specifying how much the image size is reduced at each image scale.
	 * @param minNeighbors Parameter specifying how many neighbors each candidate rectangle should have
     * to retain it.
     *
     * @return std::vector<cv::Rect> location of objects.
	 */
	std::vector<cv::Rect> objectDetection(gImage* image, std::string xmlFilePath, float scaleFactor = 1.1f, int minNeighbors = 3);

	/**
	 * Finds the locations of faces from image.
	 *
	 * @param image an image where faces are detected.
	 *
	 * @return std::vector<cv::Rect> location of faces.
	 */
	std::vector<cv::Rect> faceDetection(gImage* image);

	/**
	 * Draws squares on the image entered with locations taken from the location list.
	 *
	 * @param objects contains objects locations.
	 * @param image where the squares are drawn.
	 * @param objectname the name of the object that was drawn.
	 * @param fontsize The size of the drawn texts.
	 * @param color texts color.
	 * @param thickness texts thickness.
	 */
	void objectsDraw(std::vector<cv::Rect> objects,gImage* image, std::string objectName = "", float fontSize = 1.0f, cv::Scalar color = cv::Scalar(0, 255, 0), int thickness = 1);

	/**
	 * Finds contours.
	 *
	 * @param image an image where detection contour.
	 *
	 */
	void contourDetection(gImage* image, int thickness = 1, int thresh = 150, int maxValue = 255, cv::Scalar color = cv::Scalar(0, 255, 0));
	std::string readTextFromImage(gImage* image);

	void updateImagefromCam(gImage* image);
	void updateImagefromVideo(gImage* image);

	void setMatData(gImage* image);
	void setCam(int cam = 0);
	void setVideo(std::string videopath);
private:
	cv::Mat mat;
	cv::VideoCapture cap;
};

#endif /* SRC_GIPOPENCV_H_ */

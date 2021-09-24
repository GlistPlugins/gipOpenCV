/*
 * gipOpenCV.h
 *
 *  Created on: 13 Aðu 2021
 *      Author: berka
 */

#ifndef SRC_GIPOPENCV_H_
#define SRC_GIPOPENCV_H_

#include "opencv2/opencv.hpp"

#include "gBasePlugin.h"
#include "gImage.h"


class gipOpenCV : public gBasePlugin{

public:
	gipOpenCV();
	virtual ~gipOpenCV();

	void loadOpenCVImage(std::string fullpath);
	void contrastStretch();
	void convertToRange();
	void erode();
	void dilate();
	void blur();
	void blurGaussian();
	void invert();

private:
	std::string fullpath;
	cv::Mat sourceimage, destinationimage, binaryimage, invertedbinaryimage, grayscaleimage;
	gImage convertedimage;
};

#endif /* SRC_GIPOPENCV_H_ */

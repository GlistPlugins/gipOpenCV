/*
 * gipOpenCV.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Onur Demir
 */

#ifndef SRC_GIPOPENCV_H_
#define SRC_GIPOPENCV_H_

#include "gBasePlugin.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

class gipOpenCV : public gBasePlugin {
public:
	gipOpenCV();
	virtual ~gipOpenCV();

	void setup();
	void install();
private:
	//Mat mat;
};

#endif /* SRC_GIPOPENCV_H_ */

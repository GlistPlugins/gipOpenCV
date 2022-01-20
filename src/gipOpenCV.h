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
#include "opencv2/opencv.hpp"


using namespace cv;

class gipOpenCV : public gBasePlugin {
public:
	gipOpenCV();
	virtual ~gipOpenCV();

	gImage makeGray(gImage img);

	void setMatData(gImage img);
private:
	Mat mat;
};

#endif /* SRC_GIPOPENCV_H_ */

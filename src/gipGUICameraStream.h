/*
 * gipGUICameraStream.h
 *
 *  Created on: 12 Tem 2023
 *      Author: ademy
 */

#ifndef SRC_GIPGUICAMERASTREAM_H_
#define SRC_GIPGUICAMERASTREAM_H_

#include "gGUIControl.h"
#include "gipOpenCV.h"

class gipGUICameraStream : public gGUIControl{
public:
	gipGUICameraStream();
	virtual ~gipGUICameraStream();

	void update();
	void draw();

private:
	gipOpenCV cv;
	gTexture texture;
	cv::Mat cameraimage;
	cv::VideoCapture capture;
};

#endif /* SRC_GIPGUICAMERASTREAM_H_ */

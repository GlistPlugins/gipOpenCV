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

gImage gipOpenCV::makeGray(gImage img) {
	setMatData(img);
	gImage img2;
	cvtColor(mat, mat, COLOR_BGR2GRAY);
	cvtColor(mat, mat, COLOR_GRAY2RGBA);
	img2.setImageData(mat.data, mat.cols, mat.rows, 4);
	return img2;
}

void gipOpenCV::setMatData(gImage img) {
	mat = imread(gGetImagesDir() + "glistengine_logo.png", IMREAD_UNCHANGED);
}

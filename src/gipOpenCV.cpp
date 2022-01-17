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

void gipOpenCV::setup() {

}

void gipOpenCV::install() {
	gLogi("gipOpenCV");
	Mat mat = imread(gGetImagesDir() + "glistengine_logo.png", 0);
	/*if(mat*.empty()){
		std::cout << "Resim Yuklenemedi...";
		return;
	}
	namedWindow("deneme");
	imshow("deneme", *mat);*/
}

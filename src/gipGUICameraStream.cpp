/*
 * gipGUICameraStream.cpp
 *
 *  Created on: 12 Tem 2023
 *      Author: ademy
 */

#include "gipGUICameraStream.h"

gipGUICameraStream::gipGUICameraStream() {
	// TODO Auto-generated constructor stub
   /* capture.open(0);

    if(!capture.isOpened()) {
        std::cout << "Ein oder mehrere VideoCaptures konnten nicht geöffnet werden" << std::endl;


        capture.release();

        return;
    }
	capture.read(cameraimage);
	texture = gTexture(640, 640);
	texture.setData(cameraimage.data, false);

*/

}

gipGUICameraStream::~gipGUICameraStream() {
	// TODO Auto-generated destructor stub
}

void gipGUICameraStream::update() {
}

void gipGUICameraStream::draw() {
	texture.draw(0, 0);
}

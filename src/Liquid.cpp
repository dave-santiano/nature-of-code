#include "Liquid.h"
#include "ofMain.h"

Liquid::Liquid() {
}

Liquid::Liquid(float x, float y, float w, float h, float c)
	:x(x),
	y(y),
	w(w),
	h(h),
	c(c)
{}

void Liquid::display() {
	ofSetColor(175, 50);
	ofDrawRectangle(x, y, w, h);
}


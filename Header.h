#ifndef ATTRACTOR_H
#define ATTRACTOR_H
#pragma once
#include "ofMain.h";


class Attractor {
public:
	float mass;
	ofVec2f pos;
	Attractor();
	Attractor(ofVec2f pos, float mass);
};


#endif
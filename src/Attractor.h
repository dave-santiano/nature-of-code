#ifndef ATTRACTOR_H
#define ATTRACTOR_H
#pragma once
#include "ofMain.h"
#include "Mover.h"

class Attractor {
public:
	float mass;
	float G;
	bool attracting;
	ofVec2f pos;
	Attractor();
	void display();
	ofVec2f attract(Mover m);
};


#endif
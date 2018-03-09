#ifndef MOVER_H
#define MOVER_H

#pragma once
#include "ofMain.h"
#include "Liquid.h"

class Mover {
	public:
		ofVec2f pos, vel, acl;
		ofVec2f friction, drag;
		float speedLimit;
		float G;
		float mass;
		float mu;
		float normal;
		float cd;
		Mover();
		Mover(float m, float x, float y);
		void update();
		void display();
		void checkEdges();
		void resetForce();
		ofVec2f frictionCalc();
		void dragCalc(Liquid l);
		bool isInside(Liquid l);
		void applyForce(ofVec2f force);
		ofVec2f attract(Mover m);
		bool attracting;
	private:
};

#endif
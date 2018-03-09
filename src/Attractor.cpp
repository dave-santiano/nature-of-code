#include "Attractor.h"
#include "ofMain.h"

Attractor::Attractor()
	:pos(ofGetWidth() / 2, ofGetHeight() / 2),
	mass(100),
	G(20),
	attracting(true)
{}

void Attractor::display() {
	ofSetColor(255, 0);
	ofDrawEllipse(pos.x, pos.y, mass * 2, mass * 2);
}

ofVec2f Attractor::attract(Mover m) {
	ofVec2f force = pos - m.pos;
	float distance = force.length();
	distance = ofClamp(distance, 5.0, 500.0);
	force.normalize();

	float strength = (G * mass * m.mass) / (distance * distance);
	if (attracting == true) {
		force *= strength;
	}
	else {
		force *= strength * -1;
	}
	return force;
}
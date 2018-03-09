#include "Mover.h"
#include "ofMain.h"
Mover::Mover() 
	:mass( 1 ),
	pos( 0, 0 ),
	vel( 0, 0 ),
	acl( 0, 0 ),
	speedLimit( 5 )
{}

Mover::Mover(float m, float x, float y)
	:mass( m ),
	pos( x,y ),
	vel( 0,0 ),
	acl( 0,0 ),
	speedLimit( 3 ),
	G(5)
{}

void Mover::update() {
	vel += acl;
	vel.limit(speedLimit);
	pos += vel;
}

ofVec2f Mover::frictionCalc() {
	mu = 0.01;
	normal = 1;
	float frictionMag = mu * normal;
	friction = vel;
	friction *= -1;
	friction.normalize();
	friction *= frictionMag;
	return friction;
}

void Mover::dragCalc(Liquid l) {
	cd = 0.5;
	float speed = vel.length();
	float dragMag = l.c * speed * speed;
	drag = vel;
	drag *= -1;
	drag.normalize();
	drag *= dragMag;
	applyForce(drag);
}

void Mover::display() {
	ofSetColor(125, ofMap(pos.y,0,ofGetHeight(),200,255), ofMap(pos.x, 0, ofGetHeight(), 175, 255));
	ofSetCircleResolution(50);
	ofDrawCircle(pos.x, pos.y, mass);
}

void Mover::applyForce(ofVec2f force) {
	force /= mass;
	acl += force;
}

void Mover::resetForce() {
	acl *= 0;
}

void Mover::checkEdges() {
	float minx = 0;
	float maxx = ofGetWidth();
	float miny = 0;
	float maxy = ofGetHeight();

	if (pos.x > maxx) {
		pos.x = maxx;
		vel.x *= -1;
	}
	else if (pos.x < minx) {
		pos.x = minx;
		vel.x *= -1;
	}

	if (pos.y > maxy) {
		pos.y = maxy;
		vel.y *= -1;
	}
	else if (pos.y < miny) {
		pos.y = miny;
		vel.y *= -1;
	}
}

bool Mover::isInside(Liquid l) {
	if (pos.x > l.x && pos.x < l.x + l.w && pos.y > l.y && pos.y < l.y + l.h) {
		return true;
	}
	else {
		return false;
	}
}

ofVec2f Mover::attract(Mover m) {
	//maybe pass this in by reference instead?
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
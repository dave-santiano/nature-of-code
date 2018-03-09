#ifndef OFAPP_H
#define OFAPP_H

#pragma once
#include "ofMain.h"
#include "Mover.h"
#include "Liquid.h"
#include "Attractor.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage image;
		
		std::array<int, 20> randomCounts{};
		vector<Mover> movers;
		Liquid liquid;
		Attractor attractor;
		ofVec2f mouse;
		ofVec2f center;
		ofVec2f wind;
		ofVec2f gravity;

		int moverPopulation;
	private:
};

#endif
#include "ofApp.h"
#include "Mover.h"
#include "Liquid.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetBackgroundAuto(false);
	moverPopulation = 100;
	wind = ofVec2f(0.001, 0);
	liquid = Liquid(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2, 0.8);
	for(int i = 0; i < moverPopulation; i++){
		movers.push_back(Mover( ofRandom(0.5,300), ofRandom(0,ofGetWidth()), ofRandom(0, ofGetHeight()) ));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < movers.size(); i++) {
		for (int j = 0; j < movers.size(); j++) {
			//cout << 'i: '<< i << 'j: ' << j << '\n';
			if (i != j) {
				float m = movers[i].mass;
				ofVec2f forces = movers[j].attract(movers[i]);
				movers[i].applyForce(forces);
			}

				movers[i].checkEdges();
				movers[i].update();
				movers[i].resetForce();
		}
	}

	//for (int i = 0; i < movers.size(); i++) {
	//	if (movers[i].isInside(liquid)) {
			//movers[i].dragCalc(liquid);
		//}
		//float m = movers[i].mass;
		//ofVec2f gravity = ofVec2f(0, 0.01*m);
		//ofVec2f force = attractor.attract(movers[i]);
		//movers[i].applyForce(force);
		//movers[i].applyForce(movers[i].frictionCalc());
		//movers[i].applyForce(gravity);
	//}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < movers.size(); i++) {
		movers[i].display();
	}
	//attractor.display();
	//liquid.display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'z' && attractor.attracting == true) { 
		attractor.attracting = false; 
	}
	else {
		attractor.attracting = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(90);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetWindowTitle("Snake game");

	ofSetRectMode(OF_RECTMODE_CENTER);

	ofSetFrameRate(5);

	game.setup();
}

//----------------------------------
void ofApp::draw() {
	game.draw();
}

//----------------------------------
void ofApp::update() {
	game.update();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	game.getEvents(key);
	if (game.state == "END") {
		if (key == OF_KEY_RETURN) {
			game.reset();
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	walker = new RandomWalker();
}

//--------------------------------------------------------------
void ofApp::update(){

}

float monteCarlo() {
	while(true) {
		float random01 = ofRandom(1.0f);
		float probability = random01;
		float random02 = ofRandom(1.0f);

		if(random02 < probability) {
			return random01;
		}
	}
}

//--- Different walking strategies -----------------------------
void strategy01(int& m_x, int& m_y) {
	//--- Weight 4 directionis different ---
	int probability = rand() % 100;
	if(probability < 40) {
		m_x++;
	}
	else if(probability < 60) {
		m_x--;
	}
	else if(probability < 80) {
		m_y++;
	}
	else {
		m_y--;
	}
}

void strategy02(int& m_x, int& m_y) {
	//--- Weight 8 directionis different ---
	int probability = rand() % 100;
	if(probability < 10) {
		m_x++;
		m_y++;
	}
	else if(probability < 30) {
		m_x--;
		m_y--;
	}
	else if(probability < 50) {
		m_x--;
		m_y++;
	}
	else if(probability < 60) {
		m_x++;
		m_y--;
	}
	else if(probability < 70) {
		m_x++;
	}
	else if(probability < 80) {
		m_x--;
	}
	else if(probability < 95) {
		m_y++;
	}
	else {
		m_y--;
	}
}

void strategy03(int& m_x, int& m_y) {
	//--- Use monte carlo method ---
	float probability = monteCarlo();
	if(probability < 0.1f) {
		m_x++;
		m_y++;
	}
	else if(probability < 0.3f) {
		m_x--;
		m_y--;
	}
	else if(probability < 0.50f) {
		m_x--;
		m_y++;
	}
	else if(probability < 0.60f) {
		m_x++;
		m_y--;
	}
	else if(probability < 0.70f) {
		m_x++;
	}
	else if(probability < 0.80f) {
		m_x--;
	}
	else if(probability < 0.95f) {
		m_y++;
	}
	else {
		m_y--;
	}
}


void strategy04(int& m_x, int &m_y) {
	float stepsize = ofRandom(0, 2);

	float stepX = ofRandom(-(stepsize*stepsize), stepsize*stepsize);
	float stepY = ofRandom(-(stepsize*stepsize), stepsize*stepsize);

	m_x += stepX;
	m_y += stepY;
}


//--------------------------------------------------------------
void ofApp::draw(){
	walker->step(&strategy04);
	walker->draw(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

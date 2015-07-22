#include "ofApp.h"
#include <cmath>

void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(120);
}

void ofApp::update()
{

}

void drawCircle(ofVec2f center, float radius)
{
    ofCircle(center.x, center.y, radius);
    if(radius > 64)
    {
        drawCircle(ofVec2f{center.x + radius/2, center.y}, radius/2);
        drawCircle(ofVec2f{center.x - radius/2, center.y}, radius/2);
        drawCircle(ofVec2f{center.x, center.y + radius/2}, radius/2);
        drawCircle(ofVec2f{center.x, center.y - radius/2}, radius/2);
    }
}

void ofApp::draw()
{
    ofSetColor(255, 255, 255);
    ofNoFill();
    drawCircle(ofVec2f{ofGetWidth()/2, ofGetHeight()/2}, ofGetHeight());
}



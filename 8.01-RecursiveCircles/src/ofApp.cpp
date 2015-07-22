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

void drawCircleRecursive(ofVec2f center, float radius)
{
    ofCircle(center.x, center.y, radius);
    if(radius > 2)
    {
        radius *= 0.75f;
        drawCircleRecursive(center, radius);
    }
}

void ofApp::draw()
{
    ofSetColor(255, 255, 255);
    ofNoFill();
    drawCircleRecursive(ofVec2f{ofGetWidth()/2, ofGetHeight()/2}, ofGetHeight());
}



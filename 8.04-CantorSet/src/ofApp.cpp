#include "ofApp.h"
#include <cmath>

void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(60);
    ofSetCircleResolution(120);
}

void ofApp::update()
{

}

void cantor(float x, float y, float length)
{
    if(length >= 1)
    {
        ofLine(x, y, x+length, y);

        y += 20;
        cantor(x, y, length/3);
        cantor(x + 2 * length/3, y, length/3);
    }
}

void ofApp::draw()
{
    ofSetColor(42, 42, 42);
    ofNoFill();
    ofSetLineWidth(15);
    cantor(20, 20, ofGetWidth() - 40);
}



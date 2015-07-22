#include "ofApp.h"
#include <cmath>

KochCurve* curve;

void ofApp::generateKochCurveIterations()
{
    kochLinesB = new std::vector<KochCurve>{};
    for(KochCurve line : *kochLinesA)
    {
        kochLinesB->push_back( KochCurve{line.getA(), line.getB()} );
        kochLinesB->push_back( KochCurve{line.getB(), line.getC()} );
        kochLinesB->push_back( KochCurve{line.getC(), line.getD()} );
        kochLinesB->push_back( KochCurve{line.getD(), line.getE()} );
    }
    kochLinesA = kochLinesB;
}

void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(60);

    kochLinesA = new std::vector<KochCurve>{
            KochCurve{ ofVec2f{0, 2 * ofGetHeight()/3},
                       ofVec2f{ofGetWidth(), 2 * ofGetHeight()/3} }
    };
    kochLinesB = new std::vector<KochCurve>{};
    unsigned times = 3;
    unsigned i     = 0;
    while(i < times)
    {
        generateKochCurveIterations();
        generateKochCurveIterations();
        ++i;
    }
}

void ofApp::update()
{
}

void ofApp::draw()
{
    ofSetLineWidth(1);
    ofSetColor(42);
    for(auto line : *kochLinesA)
    {
        line.draw();
    }
}



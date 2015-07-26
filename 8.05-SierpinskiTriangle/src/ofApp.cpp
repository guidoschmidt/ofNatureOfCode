#include "ofApp.h"
#include <vector>

typedef struct
{
    ofVec2f A;
    ofVec2f B;
    ofVec2f C;
} Triangle;

std::vector<Triangle> triangles;
std::vector<Triangle> trianglesStep;

void createSierpinksiTriangle()
{
    trianglesStep = triangles;
    triangles.clear();
    for(Triangle triangle : trianglesStep)
    {
        ofVec2f vector01 = (triangle.B - triangle.A) / 2;
        ofVec2f vector02 = (triangle.C - triangle.A) / 2;

        Triangle subTriangle1
        {
            triangle.A,
            triangle.A + vector01,
            triangle.A + vector02
        };

        Triangle subTriangle2
        {
            triangle.A + vector01,
            triangle.A + vector01 * 2,
            triangle.A + vector01 + vector02
        };

        Triangle subTriangle3
        {
            triangle.A + vector02,
            triangle.A + vector02 + vector01,
            triangle.C
        };

        triangles.push_back(subTriangle1);
        triangles.push_back(subTriangle2);
        triangles.push_back(subTriangle3);
    }
}

void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(60);

    Triangle t01;
    t01.A = ofVec2f{0, ofGetHeight()};
    t01.B = ofVec2f{ofGetWidth(), ofGetHeight()};
    t01.C = ofVec2f{{ofGetWidth()/2, 0}};
    triangles.push_back(t01);

    unsigned maxRecursion = 8;
    int recursionDepth = 0;
    while(recursionDepth < maxRecursion)
    {
        createSierpinksiTriangle();
        recursionDepth++;
    }
}

void ofApp::update()
{
}

void ofApp::draw()
{
    ofFill();
    ofSetColor(42);
    for(Triangle triangle : triangles)
    {
        ofTriangle(triangle.A,
                   triangle.B,
                   triangle.C);
    }
}



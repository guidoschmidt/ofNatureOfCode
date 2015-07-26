#pragma once

#include "ofMain.h"

#include <vector>

#include "KochCurve.h"

class ofApp : public ofBaseApp
{
    private:
        std::vector<KochCurve>* kochLinesA;
        std::vector<KochCurve>* kochLinesB;
        void generateKochCurveIterations();

    public:
        void setup();
        void update();
        void draw();
};

#ifndef KOCHCURVE_H
#define KOCHCURVE_H

#include "ofMain.h"

class KochCurve
{
    private:
        ofVec2f start;
        ofVec2f end;

    public:
        KochCurve(const ofVec2f start, const ofVec2f end);
        void draw() const;
        inline ofVec2f getStart() const { return start; }
        inline ofVec2f getEnd()   const { return end; }
        ofVec2f getA() const;
        ofVec2f getB() const;
        ofVec2f getC() const;
        ofVec2f getD() const;
        ofVec2f getE() const;
};

#endif // KOCHCURVE_H

#include "KochCurve.h"

KochCurve::KochCurve(const ofVec2f start, const ofVec2f end)
: start{start}, end{end}
{
}

void KochCurve::draw() const
{
    ofLine(start.x, start.y, end.x, end.y);
}

ofVec2f KochCurve::getA() const
{
    return start;
}

ofVec2f KochCurve::getB() const
{
    ofVec2f vector = end - start;
    return start + vector/3;
}

ofVec2f KochCurve::getC() const
{
    ofVec2f vector = end - start;
    vector /= 3;
    ofVec2f newStart = start + vector;
    vector.rotate(ofRadToDeg(-45));
    return newStart + vector;
}

ofVec2f KochCurve::getD() const
{
    ofVec2f vector = end - start;
    return start + vector * 2/3;
}

ofVec2f KochCurve::getE() const
{
    return end;
}

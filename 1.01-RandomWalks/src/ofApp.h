#pragma once
#ifndef H_OFAPP
#define H_OFAPP

#include "ofMain.h"
#include "RandomWalker.h"

class ofApp : public ofBaseApp{

	private:
		RandomWalker *walker;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

#endif // H_OFAPP

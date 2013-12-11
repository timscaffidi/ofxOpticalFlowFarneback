#pragma once

#include "ofMain.h"
#include "ofxOpticalFlowFarneback.h"

#define ROWS 10
#define COLUMNS 10
#define N_CELLS ROWS*COLUMNS

class testApp : public ofBaseApp{

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
		
        ofVideoGrabber vidGrabber;
        ofxOpticalFlowFarneback flowSolver;
        float rotation[N_CELLS];
        float rotationVelocity[N_CELLS];
};

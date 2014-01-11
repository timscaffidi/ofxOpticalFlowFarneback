#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofEnableDepthTest();
	vidGrabber.setDesiredFrameRate(30);
	vidGrabber.initGrabber(320, 240);
	flowSolver.setup(vidGrabber.getWidth(), vidGrabber.getHeight(), 0.35, 5, 10, 1, 3, 2.25, false, false);
	ofEnableAlphaBlending();

	for(int i=0; i<N_CELLS; i++) {
		rotation[i] = 0;
	}
}

//--------------------------------------------------------------
void testApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate())+"fps");

	vidGrabber.update();
	if(vidGrabber.isFrameNew()) {
		flowSolver.update(vidGrabber);
	}

	// Update the rotation values & slow down velocity
	for(int i=0; i<N_CELLS; i++) {
		rotation[i] += rotationVelocity[i];
		rotationVelocity[i] *= 0.9;
	}
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(255, 255, 255);

	// We have to calculate a bunch of values so that we can
	// draw a subsection of the camera video at the correct location on the screen
	float w = ofGetWidth()/COLUMNS; // width of a single cell on the screen
	float h = ofGetHeight()/ROWS;   // height of a single cell on screen
	float sw = vidGrabber.getWidth()/COLUMNS; // width of a single cell from camera
	float sh = vidGrabber.getHeight()/ROWS;     // height of a single cell from camera
	int i=0;
	for(int row=0; row<ROWS; row++) {
		for(int column=0; column<COLUMNS; column++) {
			float x = row * w;
			float y = column * h;
			float sx = row * sw;
			float sy = column * sh;

			// Sample the flow in the middle of the grid square
			float fx = sx + (sw/2);
			float fy = sy + (sh/2);
			ofPoint flow = flowSolver.getVelAtPixel(fx, fy);
			rotationVelocity[i] += flow.length() / 3.0;

			ofPushMatrix();
			ofTranslate(x+(w/2), y);
			ofRotateY(rotation[i]);
			ofTranslate(-(w/2), 0);
			vidGrabber.getTextureReference().drawSubsection(0, 0, w, h, sx, sy, sw, sh);
			ofPopMatrix();

			i++;
		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
	if(key == 'p') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() - 0.01,0.0,1.0)); }
	else if(key == 'P') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() + 0.01,0.0,1.0)); }
	else if(key == 'l') { flowSolver.setPyramidLevels(MAX(flowSolver.getPyramidLevels() - 1,1)); }
	else if(key == 'L') { flowSolver.setPyramidLevels(flowSolver.getPyramidLevels() + 1); }
	else if(key == 'w') { flowSolver.setWindowSize(MAX(flowSolver.getWindowSize() - 1,1)); }
	else if(key == 'W') { flowSolver.setWindowSize(flowSolver.getWindowSize() + 1); }
	else if(key == 'i') { flowSolver.setIterationsPerLevel(MAX(flowSolver.getIterationsPerLevel() - 1,1)); }
	else if(key == 'I') { flowSolver.setIterationsPerLevel(flowSolver.getIterationsPerLevel() + 1); }
	else if(key == 'a') { flowSolver.setExpansionArea(MAX(flowSolver.getExpansionArea() - 2,1)); }
	else if(key == 'A') { flowSolver.setExpansionArea(flowSolver.getExpansionArea() + 2); }
	else if(key == 's') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() - 0.01,0.0,10.0)); }
	else if(key == 'S') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() + 0.01,0.0,10.0)); }
	else if(key == 'f') { flowSolver.setFlowFeedback(false); }
	else if(key == 'F') { flowSolver.setFlowFeedback(true); }
	else if(key == 'g') { flowSolver.setGaussianFiltering(false); }
	else if(key == 'G') { flowSolver.setGaussianFiltering(true); }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {

}

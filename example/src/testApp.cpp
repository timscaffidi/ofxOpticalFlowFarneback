#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    vidPlayer.loadMovie("Godard.mov");
    vidPlayer.play();
    flowSolver.setup(vidPlayer.getWidth(), vidPlayer.getHeight(), 0.5, 3, 10, 1, 7, 1.5, false, false);
    flowSolver2.setup(vidPlayer.getWidth(), vidPlayer.getHeight());
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(true);
    ofBackground(0);
    

}

//--------------------------------------------------------------
void testApp::update(){
    vidPlayer.update();
    if(vidPlayer.isFrameNew()){
        flowSolver.update(vidPlayer);
        //flowSolver2.update(vidPlayer);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    ofFill();
    ofRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(255, 255, 255);
    vidPlayer.draw(0, 0,vidPlayer.getWidth()*2, vidPlayer.getHeight()*2);
    flowSolver.drawColored(vidPlayer.getWidth()*2, vidPlayer.getHeight()*2, 10, 3);
    //flowSolver2.drawColored(vidPlayer.getWidth()*2, vidPlayer.getHeight()*2, 10, 3);
    
    stringstream m;
    m << "fps " << ofGetFrameRate() << endl
    << "pyramid scale: " << flowSolver.getPyramidScale() << " p/P" << endl
    << "pyramid levels: " << flowSolver.getPyramidLevels() << " l/L" << endl
    << "averaging window size: " << flowSolver.getWindowSize() << " w/W" << endl
    << "iterations per level: " << flowSolver.getIterationsPerLevel() << " i/I" << endl
    << "expansion area: " << flowSolver.getExpansionArea() << " a/A" << endl
    << "expansion sigma: " << flowSolver.getExpansionSigma() << " s/S" << endl
    << "flow feedback: " << flowSolver.getFlowFeedback() << " f/F" << endl
    << "gaussian filtering: " << flowSolver.getGaussianFiltering() << " g/G";
    
    ofDrawBitmapString(m.str(), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
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
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
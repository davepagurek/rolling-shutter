#include "ofApp.h"

constexpr int memory = 4;

ofVideoPlayer player;
ofFbo composite;
int frame = -1;

constexpr int rowsPerFrame = 4;
std::vector<ofxCvColorImage> buffer;

//--------------------------------------------------------------
void ofApp::setup(){
  player.load("dance.mp4");
  player.setLoopState(OF_LOOP_NORMAL);
  player.play();

  composite.allocate(player.getWidth(), player.getHeight(), GL_RGBA);
  
  for (int i = 0; i < player.getHeight()/rowsPerFrame; i++) {
    buffer.emplace_back();
    buffer.back().allocate(player.getWidth(), player.getHeight());
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  player.getCurrentFrame();
  if (player.isFrameNew()) {
    frame++;
    
    buffer[frame % buffer.size()].setROI(0, 0, player.getWidth(), player.getHeight());
    buffer[frame % buffer.size()].setFromPixels(player.getPixels());
    composite.begin();
    for (int i = 0; i < std::min(frame, (int)buffer.size()); i++) {
      int y = i * rowsPerFrame;
      buffer[(frame - i + buffer.size()) % buffer.size()].setROI(0, y, player.getWidth(), rowsPerFrame);
      buffer[(frame - i + buffer.size()) % buffer.size()].drawROI(0, y, player.getWidth(), rowsPerFrame);
    }
    composite.end();
  }
  
  composite.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  frame = -1;
  player.firstFrame();
  player.play();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

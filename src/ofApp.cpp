#include "ofApp.h"

int NA;
const float AGENT_SPEED = 1;
glm::vec2 ssize;
//--------------------------------------------------------------
void ofApp::setup(){
	NA = ofGetWidth() * ofGetHeight();
	printf("%i\n", NA); 
	shader.load("vert.glsl", "frag.glsl");
	ssize = ofGetWindowSize();

	cells.resize(NA);
	int breg = 1000;
	for (int x = 0; x < ofGetWidth(); x++) {
		for (int y = 0; y < ofGetHeight(); y++) {
			Cell cell = cells[x + y * ofGetWidth()];
			cell.a = 1;
			cell.b = x<breg && y<breg ? 1 : 0;
		}
	}
	cellBuffer.allocate(cells, GL_DYNAMIC_DRAW);

	cellBuffer.bindBase(GL_SHADER_STORAGE_BUFFER, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	shader.begin();
	shader.setUniform2f("ssize", ssize);
	shader.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

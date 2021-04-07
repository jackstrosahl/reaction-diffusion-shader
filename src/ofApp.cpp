#include "ofApp.h"

const int NA = 100000;
const float AGENT_SPEED = 1;
//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("vert.glsl", "frag.glsl");

	agents.resize(NA);
	for (auto &agent: agents) {
		agent.pos.set(ofRandomWidth(), ofRandomHeight());
		const float a = ofRandom(TWO_PI);
		agent.vel.set(AGENT_SPEED * cos(a), AGENT_SPEED * sin(a));
		agent.col.set(ofRandom(1.0), ofRandom(1.0), ofRandom(1.0), 1.0);
	}
	agentBuffer.allocate(agents, GL_DYNAMIC_DRAW);

	compute.loadCompute("comp.glsl");
	

	trails.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA8);
	trails.bindAsImage(0, GL_READ_WRITE);
	agentBuffer.bindBase(GL_SHADER_STORAGE_BUFFER, 1);
}

//--------------------------------------------------------------
void ofApp::update(){

	ofVec2f ssize;
	ssize.set(ofGetWidth(), ofGetHeight());
	compute.begin();
	compute.setUniform2f("ssize", ssize);
	compute.dispatchCompute(NA, 1, 1);
	compute.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	/*
	shader.begin();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
	*/

	trails.draw(0, 0, ofGetWidth(), ofGetHeight());
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

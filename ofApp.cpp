#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(2);
	ofNoFill();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 300;

	for (int i = 0; i < 10; i++) {

		ofRotateZ(3);

		for (int k = 0; k < 12; k++) {

			ofColor color;
			color.setHsb(ofMap(k, 0, 12, 0, 255), 255, 255);
			ofSetColor(color);

			ofBeginShape();
			for (float theta_deg = k * 180 + 0.5; theta_deg < k * 180 + 180; theta_deg += 0.5) {

				auto phi_deg = ofMap(ofNoise(theta_deg * 0.002 + ofGetFrameNum() * 0.0025), 0, 1, -1440, 1440);

				auto location = glm::vec3(
					radius * sin(theta_deg * DEG_TO_RAD) * cos(phi_deg * DEG_TO_RAD),
					radius * sin(theta_deg * DEG_TO_RAD) * sin(phi_deg * DEG_TO_RAD),
					0);
				
				ofVertex(location);
			}
			ofEndShape();
		}
	}

	this->cam.end();

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
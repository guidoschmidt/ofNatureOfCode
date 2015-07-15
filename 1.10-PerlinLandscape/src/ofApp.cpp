#include "ofApp.h"
#include <cmath>

int m_octaves     = 6;
float m_frequency = 0.25f;
float m_amplitude = 0.5f;
int m_seed        = 10.0f;

ofPlanePrimitive plane;
ofMesh* planePtr;

//--------------------------------------------------------------
void ofApp::generateLandscapeFromNoise()
{
	plane.set(1000, 1000);   ///dimensions for width and height in pixels
	plane.setPosition(0, 0, 0); /// position in x y z
	plane.setResolution(100, 100);

	_mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	msa::Perlin perlin;
	perlin.setup(m_octaves, m_frequency, m_amplitude, m_seed);

	planePtr = plane.getMeshPtr();
	planePtr->setMode(OF_PRIMITIVE_POINTS);
	std::vector<ofVec3f> vertices = planePtr->getVertices();
	for(unsigned int i=0; i < vertices.size(); ++i)
	{
		std::cout << vertices[i] << std::endl;
		float height = ofNoise( vertices[i].x/1024.0f,
								vertices[i].y/1024.0f);
		float perlinHeight = perlin.get(vertices[i].x/200, vertices[i].y/200);
		float spreadHeight = ofMap(perlinHeight, 0, 1, 0, 255);
		ofVec3f myVertex(vertices[i].x,vertices[i].y, spreadHeight);
		_mesh.addVertex(myVertex);
		_mesh.addColor(0.5);
	}

	std::vector<ofIndexType> indices = planePtr->getIndices();
	for(unsigned int i=0; i < indices.size(); ++i)
	{
		_mesh.addIndex(indices[i]);
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	generateLandscapeFromNoise();
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(255);
	_easyCam.begin();
		//_mesh.draw();
		_mesh.drawWireframe();
		//planePtr->draw();
		//plane.drawWireframe();
	_easyCam.end();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

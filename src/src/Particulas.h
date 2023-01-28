#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Particulas : public ofxBox2dRect
{
public:
	void setup(ofxBox2d &box2d, float x, float y);
	void update();
	void draw();


private:
	float x1, y1;
	ofImage particulaimg;
};
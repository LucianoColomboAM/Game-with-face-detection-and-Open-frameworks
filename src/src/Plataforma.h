#pragma once


#include "ofMain.h"
#include "ofxBox2d.h"


class Plataforma : public ofxBox2dRect
{
public:
  void setup(ofxBox2d &box2d, float x, float y,float w, float h, string tipo);
  void draw();
  void update();
  void setPunteros(float x, float y, float x1, float y1);

private:
  string tipop;
  ofImage m_imagen;

  float ojox, ojoy, manox, manoy;
 
};
#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "Particulas.h"

class Personaje : public ofxBox2dRect
{
public:
  void setup(ofxBox2d &box2d, float x, float y, float n);
  void update();
  void draw();
  bool getDestruido() const;
  vector<shared_ptr<Particulas>> particulas;

  void setDestruido(bool destruir);
  void setPunteros(float x, float y, float x1, float y1);
  
private:

	ofxBox2d  xd;
	float x1, y1;
  float ojox, ojoy, manox, manoy;
  bool m_destruido;
  ofImage objeto;
  int tiempoFrame;
  int indiceImagen;
  bool parado;
  bool mirarDerecha;
};
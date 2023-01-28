#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Enemigo : public ofxBox2dRect
{
public:
  void setup(ofxBox2d &box2d, float x, float y);
  void update();
  void draw();

  // Este método lo usaremos para destruir al goomba luego de que esté
  // un tiempo muerto. Solamente nos hace falta el getter.
  bool getDestruido() const;

  // Este método lo usaremos para matar al goomba en la colisión. En este
  // caso solo nos hará falta el setter.
  void setMuerto(bool destruir);

  

private:
  ofImage goomba[2];
  ofImage goombaMuerto;

  // Cuantos frames de oF tienen que pasar para que cambie un frame de la
  // animación del goomba al caminar.
  int tiempoFrame;
  int indiceImagen;  
  bool direccionDerecha;
  ofVec2f posicionInicio;
  bool m_destruido;
  bool m_muerto;

  // Para que la imagen del goomba muerto esté un tiempo visible antes de
  // que se destruya por completo (con destroy).
  float tiempoMuerto;

};
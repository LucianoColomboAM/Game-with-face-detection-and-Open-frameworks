#include "Plataforma.h"

///////////////////////////////////////////////////////////////////////////
void Plataforma::setup(ofxBox2d &box2d, float x, float y, float w, float h, string tipo)
{
	tipop = tipo;
  if (tipo == "plataforma")
  {
    setPhysics(0, 0, 0.5f);
    ofxBox2dRect::setup(box2d.getWorld(), x, y, w, h);
	
    name = "plataforma";
    setData(this);
    m_imagen.load("plataforma.png");
  }
  else if (tipo == "piso")
  {
    setPhysics(0, 0, 0.5f);
    ofxBox2dRect::setup(box2d.getWorld(), x, y,	w, h);
    name = "plataforma";
    setData(this);
    m_imagen.load("piso.png");
  }

  else if (tipo == "invisible")
  {
	  setPhysics(0, 0, 0.5f);
	  ofxBox2dRect::setup(box2d.getWorld(), x, y, w, h);
	  name = "plataforma";
	  setData(this);
  }
}


void Plataforma::update() 

{
	if (tipop == "invisible")
	{

		if (ojox >= getPosition().x - 50 &&
			ojoy >= getPosition().y - 50 &&
			ojox <= getPosition().x + 25 &&
			ojoy <= getPosition().y
			)
		{
			destroy();
			shouldRemove;
		}
	}
}
///////////////////////////////////////////////////////////////////////////
void Plataforma::draw()
{
	
  ofSetRectMode(OF_RECTMODE_CENTER);
  m_imagen.draw(getPosition(),getWidth(),getHeight());
  ofSetRectMode(OF_RECTMODE_CORNER);
}

///////////////////////////////////////////////////////////////////////////
void Plataforma::setPunteros(float x, float y, float x1, float y1) 
{ 
	ojox = x;
	ojoy = y;
	manox = x1;
	manoy = y1;
}
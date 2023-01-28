#include "Personaje.h"

void Personaje::setup(ofxBox2d &box2d, float x, float y, float n)
{
	xd = box2d;
	x1 = x;
	y1 = y;
  setPhysics(20, 0.5, 1);
  ofxBox2dRect::setup(box2d.getWorld(), x, y, 75, 75);
  name = "personaje";
  setData(this);
  setFixedRotation(true);

  objeto.load("objeto_" + ofToString(n) + ".png");
 // marioParadoDerecha.load("mario_parado.png");

  indiceImagen = 0;

}

///////////////////////////////////////////////////////////////////////////
void Personaje::update()
{

	if (ojox >= getPosition().x - getWidth()/2 &&
		ojoy >= getPosition().y - getHeight()/2 &&
		ojox <= getPosition().x + getWidth() / 2 &&
		ojoy <= getPosition().y + getHeight() / 2
		)
	{
		setVelocity(ofRandom(-15,15), ofRandom(0, 10));

		int dado = ofRandom(0, 10);

		if (dado>=9) {
		
			destroy();
			shouldRemoveOffScreen;
			for (int i = 0; i < 10; i++)
			{
				particulas.push_back(make_shared<Particulas>());
				particulas.back()->setup(xd, x1, y1);
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			particulas.push_back(make_shared<Particulas>());
			particulas.back()->setup(xd, x1,y1);
		}
	}
/*
	if (manox >= getPosition().x - getWidth() / 2 &&
		manoy >= getPosition().y - getHeight() / 2 &&
		manox <= getPosition().x + getWidth() / 2 &&
		manoy <= getPosition().y + getHeight() / 2
		)
	{
		
		destroy();
		for (int i = 0; i < 50; i++)
		{
			particulas.push_back(make_shared<Particulas>());
			particulas.back()->setup(xd, x1,y1);
		}
		
	}

	*/
}

///////////////////////////////////////////////////////////////////////////
void Personaje::draw()
{
  ofSetRectMode(OF_RECTMODE_CENTER);

 
	  objeto.draw(getPosition(), getWidth(), getHeight());
	  for (auto &particula : particulas) particula->draw();
   

  ofSetRectMode(OF_RECTMODE_CORNER);
}

///////////////////////////////////////////////////////////////////////////
void Personaje::setPunteros(float x, float y, float x1, float y1)
{
	ojox = x;
	ojoy = y;
	manox = x1;
	manoy = y1;
}
///////////////////////////////////////////////////////////////////////////
bool Personaje::getDestruido() const { return m_destruido; }
void Personaje::setDestruido(bool destruido) { m_destruido = destruido; }


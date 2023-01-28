#include "Enemigo.h"

///////////////////////////////////////////////////////////////////////////
void Enemigo::setup(ofxBox2d &box2d, float x, float y)
{
	setPhysics(1, 0.05, 50);
	ofxBox2dRect::setup(box2d.getWorld(), x, y, 48, 48);
	name = "goomba";
	setData(this);

	int dado = ofRandom(0, 2);

	if (dado == 0) 
	{
		for (int i = 0; i < 2; i++)
		{
			goomba[i].load("hombre_" + ofToString(i) + ".png");
			goombaMuerto.load("hombre_muerto.png");
		}
	}
	if (dado == 1)
	{

		for (int i = 0; i < 2; i++) 
		{
		goomba[i].load("mujer_" + ofToString(i) + ".png");
		goombaMuerto.load("mujer_muerta.png");

		}
	}
  // Cada 10 frames de oF cambiará un frame de la animación.
  tiempoFrame = 10;

  indiceImagen = 0;
  m_destruido = false;
  m_muerto = false;

  // Generamos un valor entero aleatorio 0 o 1 (false o true).
  direccionDerecha = (int)ofRandom(2);
  posicionInicio.set(x, y);

  // El tiempo que estará la imagen del goomba muerto.
  // 30 cuadros son medio segundo (60 cuadros son un segundo).
  tiempoMuerto = 30;

  setFixedRotation(true);
}

///////////////////////////////////////////////////////////////////////////
void Enemigo::update()
{
  if (!m_muerto)
  {
    // Si la posición en X está dentro del rango (posicionInicio.x - 45) y
    // (getPosition().x + 45) estas líneas no se ejecutan. Solo se
    // produce el cambio de dirección cuando la posición en X del goomba
    // se pasa del rango.
    if (getPosition().x > posicionInicio.x + 45)
      direccionDerecha = false;

    else if (getPosition().x < posicionInicio.x - 45)
      direccionDerecha = true;

    if (direccionDerecha)
      setVelocity(2.5f, getVelocity().y);
    else
      setVelocity(-2.5f, getVelocity().y);

    // La animación del goomba. Esto es verdadero cada 10 frames de oF.
    if (ofGetFrameNum() % tiempoFrame == 0) indiceImagen++;

    indiceImagen = indiceImagen >= 2 ? 0 : indiceImagen;
  }
  // Si el goomba está muerto, hacemos que pase un tiempo con la imagen
  // del goomba muerto y luego lo destruimos definitivamente.
  else
  {    
    setVelocity(0, 0);
    
    // Para que el goomba quede muerto en el lugar.
    setDensity(1000);

    // Para que el cambio de densidad se aplique.
    body->ResetMassData();

    // Si pasaron los 30 cuadros entonces lo destruimos definitivamente.
    tiempoMuerto--;
    if (tiempoMuerto <= 0 ) m_destruido = true;
  }
}

///////////////////////////////////////////////////////////////////////////
void Enemigo::draw()
{
  ofSetRectMode(OF_RECTMODE_CENTER);

  if (!m_muerto) goomba[indiceImagen].draw(getPosition(),getWidth(), getHeight());
  else goombaMuerto.draw(getPosition(),getWidth(), getHeight());

  ofSetRectMode(OF_RECTMODE_CORNER);
}

///////////////////////////////////////////////////////////////////////////
bool Enemigo::getDestruido() const { return m_destruido; }
void Enemigo::setMuerto(bool muerto) { m_muerto = muerto; }
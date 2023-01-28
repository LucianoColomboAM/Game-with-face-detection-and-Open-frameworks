#include "ofApp.h"

///////////////////////////////////////////////////////////////////////////
void ofApp::setup()
{

	ofSetWindowShape(800, 600);

	ofToggleFullscreen();
	//ofSetFullscreen(true);
	ofSetFrameRate(120);
	ofSetBackgroundColor(0, 0, 0);
	cam.setup(640, 480);
	
	finder.setup("haarcascade_frontalface_default.xml");
	finder2.setup("hand.xml");
	finder.setPreset(ObjectFinder::Fast);
	finder2.setPreset(ObjectFinder::Fast);

  
	box2d.init();
	box2d.setFPS(30);
	box2d.setGravity(0, 8);
	box2d.createBounds();
	box2d.registerGrabbing();
	box2d.enableEvents();

	piso.setup(box2d, ofGetWidth() / 2, ofGetHeight() - 5,ofGetWidth(),10, "piso");

	


	objeto[0].setup(box2d, ofGetWidth()/4, 100, 1);
	techo[0].setup(box2d, ofGetWidth() / 4, 200, 1, 1, "invisible");

	objeto[1].setup(box2d, (ofGetWidth() / 4)*3,100, 2);
	techo[1].setup(box2d, (ofGetWidth() / 4) * 3, 200, 1, 1, "invisible");
	

	objeto[2].setup(box2d, ofGetWidth() / 2, 100, 3);
	techo[2].setup(box2d, (ofGetWidth() / 2), 200, 1, 1, "invisible");


	objeto[3].setup(box2d, (ofGetWidth() / 4), ofGetHeight()-200, 4);
	techo[3].setup(box2d, (ofGetWidth() / 4), ofGetHeight() - 100, 1, 1, "invisible");


	objeto[4].setup(box2d, (ofGetWidth() / 4)*3, ofGetHeight() - 200, 4);
	techo[4].setup(box2d, (ofGetWidth() / 4)*3, ofGetHeight() - 100, 1, 1, "invisible");


	objeto[5].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 200, 5);
	techo[5].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 100, 1, 1, "invisible");


	objeto[6].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 200, 6);
	techo[6].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 100, 1, 1, "invisible");


	objeto[7].setup(box2d, 100, ofGetHeight() - 200, 5);
	techo[7].setup(box2d, 100, ofGetHeight() - 100, 1, 1, "invisible");


	objeto[8].setup(box2d,100, ofGetHeight() - 200, 6);
	techo[8].setup(box2d, 100, ofGetHeight() - 100, 1, 1, "invisible");

	objeto[9].setup(box2d, (ofGetWidth() / 4) * 3+50, ofGetHeight() - 200, 7);
	techo[9].setup(box2d, (ofGetWidth() / 4) * 3+50, ofGetHeight() - 100, 1, 1, "invisible");

	objeto[10].setup(box2d, (ofGetWidth() / 4) + 50, ofGetHeight() - 200, 7);
	techo[10].setup(box2d, (ofGetWidth() / 4) + 50, ofGetHeight() - 100, 1, 1, "invisible");

	objeto[11].setup(box2d, (ofGetWidth() / 4)+100, ofGetHeight() /4, 8);
	techo[11].setup(box2d, (ofGetWidth() / 4)+100, ofGetHeight() /4+100, 1, 1, "invisible");

	objeto[12].setup(box2d, (ofGetWidth() / 4)*3-100, ofGetHeight() /4, 8);
	techo[12].setup(box2d, (ofGetWidth() / 4)*3-100, ofGetHeight() /4+100, 1, 1, "invisible");



	objeto[13].setup(box2d, ofGetWidth() / 4-150, 100, 1);
	techo[13].setup(box2d, ofGetWidth() / 4-150, 200, 1, 1, "invisible");

	objeto[14].setup(box2d, (ofGetWidth() / 4) * 3+150, 100, 2);
	techo[14].setup(box2d, (ofGetWidth() / 4) * 3+150, 200, 1, 1, "invisible");

	objeto[15].setup(box2d, (ofGetWidth() / 2+300), ofGetHeight()/4*3, 9);
	techo[15].setup(box2d, (ofGetWidth() / 2)+300, ofGetHeight() /4*3 + 100, 1, 1, "invisible");

	objeto[16].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 +150 , 10);
	techo[16].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4  + 200, 1, 1, "invisible");

	objeto[17].setup(box2d, (ofGetWidth() / 2) -150, ofGetHeight() / 4 * 3, 11);
	techo[17].setup(box2d, (ofGetWidth() / 2) -150, ofGetHeight() / 4 * 3 + 100, 1, 1, "invisible");

	objeto[18].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 * 3, 12);
	techo[18].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 * 3 + 100, 1, 1, "invisible");
	




	
	ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);

	inicio = true;
	fin = false;

	fuente.load("BirchStd.otf", 15);
	fuenteGrande.load("BirchStd.otf", 50);
	fondo.load("fondo.png");
	fondoInicio.load("fondoinicio.png");

	
	
		plataformas.push_back(make_shared<Plataforma>());
		plataformas.back()->setup(box2d, ofGetWidth()/2-100 , ofGetHeight() / 4 * 3+100, 300,16, "plataforma");

	ofVec2f plataforma = plataformas.back()->getPosition();
	

	// Creamos tres goombas en el vector.
	for (int i = 0; i < 25; i++) goombas.push_back(make_shared<Enemigo>());

	// Inicializamos los goombas.
	// Los primeros dos goombas los creamos en el piso.

	for (int i = 0; i < 25; i++) goombas[i]->setup(box2d, ofRandom(10, ofGetWidth() - 10), ofGetHeight() - 30);
 
	// Al último goomba los ponemos sobre la plataforma extra.

	gritos.load("gritos.wav");
	golpes.load("golpes.wav");
	risas.load("risas.wav");
	risas.setLoop(loop);
	risas.play();
	ofGetCurrentTime();

}

///////////////////////////////////////////////////////////////////////////
void ofApp::update()
{
	

	
	cam.update();
	if (cam.isFrameNew())
	{

		finder.update(cam);
		finder2.update(cam);
	}
	for (int i = 0; i < finder.size(); i++)
	{
		ofRectangle object = finder.getObjectSmoothed(i);
		punterox = (object.x + object.width / 2);
	
		punterox = ofMap(object.x + object.width / 2, 0, cam.getWidth(), ofGetWidth()*-2, ofGetWidth()* 3);
		punterox = ofMap(punterox, 0, ofGetWidth(), ofGetWidth(), 0);

		// punterox=ofMap()

		punteroy = (object.y + object.height / 2);
		punteroy = ofMap(object.y + object.height / 2, 0, cam.getHeight(), ofGetHeight()* -2 , ofGetHeight()*4);


	
	}
	for (int i = 0; i < finder2.size(); i++)
	{
		ofRectangle object1 = finder2.getObjectSmoothed(i);
		punterox1 = (object1.x);
		punterox1= ofMap(object1.x, 0, cam.getWidth(), ofGetWidth()* -2, ofGetWidth() * 4);
		punteroy1 = (object1.y);
		punteroy1 = ofMap(object1.y, 0, cam.getHeight(), ofGetHeight()* -2, ofGetHeight() * 4);
	}
	
		

	for (int i = 0; i < 19; i++) {
	
		techo[i].setPunteros(punterox, punteroy, punterox1, punteroy1);
		objeto[i].setPunteros(punterox, punteroy, punterox1, punteroy1);
	}




  if (!inicio)
  {
    box2d.update();
	

	for (int i = 0; i < 19; i++) {
		objeto[i].update();
		techo[i].update();
		if (objeto[i].getDestruido() && objeto[i].alive) objeto[i].destroy();
	}
  



	

    for (auto &goomba : goombas)
    { 
      goomba->update();

      if (goomba->getDestruido() && goomba->alive) goomba->destroy();
    }

    ofRemove(goombas, ofxBox2dBaseShape::shouldRemove);   
  }
}

///////////////////////////////////////////////////////////////////////////
void ofApp::draw()
{
	
	
	

  if (inicio)
  {
	fondoInicio.draw(0, 0, ofGetWidth(), ofGetHeight());
	
  }
  else
  {
	 

	  fondo.draw(0, 0, ofGetWidth(), ofGetHeight());
	  ojo.load("ojo.png");
	  ojo.draw(punterox - 10, punteroy - 10, 20, 20);
	  manos.load("manos.png");
	  manos.draw(punterox1 - 20, punteroy1 - 20, 30, 30);

	  
	  int tiempo = ofGetElapsedTimef();
	  if (loop == true && tiempo % 10 == 0)
	  {
		  risas.getVolume() + 2;
	  }

	  if (loop == false && tiempo % 10 == 0)
	  {
		  risas.stop();
		  gritos.play();
		  gritos.setLoop(true);
	  }


	  if (tiempo % 10 == 0) {
		   dado = ofRandom(0, 11);
	  }

	  if (dado == 1) {
	  fuente.drawString(bullying1, ofGetWidth()/2, ofGetHeight()/2);
	  }

	  if (dado == 2) {
		  fuente.drawString(bullying2, ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 3) {
		  fuente.drawString(bullying3, ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 4) {
		  fuente.drawString(bullying4, ofGetWidth() / 2 - 220, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 5) {
		  fuente.drawString(bullying5, ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 6) {
		  fuente.drawString(bullying6, ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 7) {
		  fuente.drawString(bullying7, ofGetWidth() / 2 - 250, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 8) {
		  fuente.drawString(bullying8, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 9) {
		  fuente.drawString(bullying9, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 20);
	  }
	  if (dado == 10) {
		  fuente.drawString(bullying10, ofGetWidth() / 2-50, ofGetHeight() / 2+20);
	  }


    if (fin) 
    {
      ofSetColor(0);
      fuenteGrande.drawString(texto, 100, 130);
      fuente.drawString("ENTER para continuar", 100, 190);
      ofSetColor(255);
    }


	//ofDrawRectangle(mario.getPosition().x, mario.getPosition().y, mario.getWidth(), mario.getHeight());
	for (auto &plataforma : plataformas) plataforma->draw();

    plataformaExtra.draw();
    piso.draw();


	for (int i = 0; i < 19; i++) {
		objeto[i].draw();
		techo[i].draw();
	}


    for (auto &goomba : goombas) goomba->draw();
	ofSetColor(255);
	
  }
}

///////////////////////////////////////////////////////////////////////////
void ofApp::keyPressed(int key)
{

	if (key == 'r')
	{
		//ofToggleFullscreen();
		reset();
	}

  if (key == OF_KEY_RETURN)
  {
    if (inicio) inicio = false;
    else if(fin) 
    {
      inicio = true;
      reset();
    }
  } 
}

///////////////////////////////////////////////////////////////////////////
void ofApp::keyReleased(int key)
{

}

///////////////////////////////////////////////////////////////////////////
void ofApp::contactStart(ofxBox2dContactArgs &e)
{
  if (e.a != NULL && e.b != NULL)
  {
    if (e.a->GetType() != b2Shape::e_edge && e.b->GetType() != b2Shape::e_edge)
    {
      ofxBox2dBaseShape *objeto_a = (ofxBox2dBaseShape *)e.a->GetBody()->GetUserData();
      ofxBox2dBaseShape *objeto_b = (ofxBox2dBaseShape *)e.b->GetBody()->GetUserData();

      b2ContactEdge *contactEdge = e.a->GetBody()->GetContactList();
      b2WorldManifold contacto;
      contactEdge->contact->GetWorldManifold(&contacto);
      b2Vec2 vector_normal = contacto.normal;
      ofVec2f direccion = box2d.toOf(vector_normal);

	


      if (objeto_a->name == "personaje" || objeto_b->name == "personaje" || objeto_a->name == "particula" || objeto_b->name == "particula")
      {
        
        Enemigo *enemigo_a = (Enemigo *)e.a->GetBody()->GetUserData();
        Enemigo *enemigo_b = (Enemigo *)e.b->GetBody()->GetUserData();
        
        // En este caso evaluamos que la colisión sea desde arriba
        // verificando que la velocidad de Mario en el eje Y sea positiva 
        // en el momento de la colisión.
        if (enemigo_a->name == "goomba") 
        {
			gritos.play();
			golpes.play();
			loop = false;
            enemigo_a->setMuerto(true);
	
        }
        else if (enemigo_b->name == "goomba")
        {
			gritos.play();
			golpes.play();
			loop = false;
            enemigo_b->setMuerto(true);
         
        }       
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////
void ofApp::contactEnd(ofxBox2dContactArgs &e) {}

///////////////////////////////////////////////////////////////////////////
void ofApp::reset()
{
  inicio = false;

  
  
  ofVec2f plataforma;
  objeto[0].setup(box2d, ofGetWidth() / 4, 100, 1);
  techo[0].setup(box2d, ofGetWidth() / 4, 200, 1, 1, "invisible");

  objeto[1].setup(box2d, (ofGetWidth() / 4) * 3, 100, 2);
  techo[1].setup(box2d, (ofGetWidth() / 4) * 3, 200, 1, 1, "invisible");


  objeto[2].setup(box2d, ofGetWidth() / 2, 100, 3);
  techo[2].setup(box2d, (ofGetWidth() / 2), 200, 1, 1, "invisible");


  objeto[3].setup(box2d, (ofGetWidth() / 4), ofGetHeight() - 200, 4);
  techo[3].setup(box2d, (ofGetWidth() / 4), ofGetHeight() - 100, 1, 1, "invisible");


  objeto[4].setup(box2d, (ofGetWidth() / 4) * 3, ofGetHeight() - 200, 4);
  techo[4].setup(box2d, (ofGetWidth() / 4) * 3, ofGetHeight() - 100, 1, 1, "invisible");


  objeto[5].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 200, 5);
  techo[5].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 100, 1, 1, "invisible");


  objeto[6].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 200, 6);
  techo[6].setup(box2d, (ofGetWidth() - 100), ofGetHeight() - 100, 1, 1, "invisible");


  objeto[7].setup(box2d, 100, ofGetHeight() - 200, 5);
  techo[7].setup(box2d, 100, ofGetHeight() - 100, 1, 1, "invisible");


  objeto[8].setup(box2d, 100, ofGetHeight() - 200, 6);
  techo[8].setup(box2d, 100, ofGetHeight() - 100, 1, 1, "invisible");

  objeto[9].setup(box2d, (ofGetWidth() / 4) * 3 + 50, ofGetHeight() - 200, 7);
  techo[9].setup(box2d, (ofGetWidth() / 4) * 3 + 50, ofGetHeight() - 100, 1, 1, "invisible");

  objeto[10].setup(box2d, (ofGetWidth() / 4) + 50, ofGetHeight() - 200, 7);
  techo[10].setup(box2d, (ofGetWidth() / 4) + 50, ofGetHeight() - 100, 1, 1, "invisible");

  objeto[11].setup(box2d, (ofGetWidth() / 4) + 100, ofGetHeight() / 4, 8);
  techo[11].setup(box2d, (ofGetWidth() / 4) + 100, ofGetHeight() / 4 + 100, 1, 1, "invisible");

  objeto[12].setup(box2d, (ofGetWidth() / 4) * 3 - 100, ofGetHeight() / 4, 8);
  techo[12].setup(box2d, (ofGetWidth() / 4) * 3 - 100, ofGetHeight() / 4 + 100, 1, 1, "invisible");



  objeto[13].setup(box2d, ofGetWidth() / 4 - 150, 100, 1);
  techo[13].setup(box2d, ofGetWidth() / 4 - 150, 200, 1, 1, "invisible");

  objeto[14].setup(box2d, (ofGetWidth() / 4) * 3 + 150, 100, 2);
  techo[14].setup(box2d, (ofGetWidth() / 4) * 3 + 150, 200, 1, 1, "invisible");

  objeto[15].setup(box2d, (ofGetWidth() / 2 + 300), ofGetHeight() / 4 * 3, 9);
  techo[15].setup(box2d, (ofGetWidth() / 2) + 300, ofGetHeight() / 4 * 3 + 100, 1, 1, "invisible");

  objeto[16].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 + 150, 10);
  techo[16].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 + 200, 1, 1, "invisible");

  objeto[17].setup(box2d, (ofGetWidth() / 2) - 150, ofGetHeight() / 4 * 3, 11);
  techo[17].setup(box2d, (ofGetWidth() / 2) - 150, ofGetHeight() / 4 * 3 + 100, 1, 1, "invisible");

  objeto[18].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 * 3, 12);
  techo[18].setup(box2d, (ofGetWidth() / 2), ofGetHeight() / 4 * 3 + 100, 1, 1, "invisible");


  // Inicializamos los goombas nuevamente.
	 goombas.clear();
	plataformas.push_back(make_shared<Plataforma>());
	plataformas.back()->setup(box2d, ofGetWidth()/2-100 , ofGetHeight() / 4 * 3+100, 300,16, "plataforma");
	 plataforma = plataformas.back()->getPosition();
	

	// Creamos tres goombas en el vector.
	for (int i = 0; i < 25; i++) goombas.push_back(make_shared<Enemigo>());

	// Inicializamos los goombas.
	// Los primeros dos goombas los creamos en el piso.

	for (int i = 0; i < 25; i++) goombas[i]->setup(box2d, ofRandom(10, ofGetWidth() - 10), ofGetHeight() - 30);
 
	// Al último goomba los ponemos sobre la plataforma extra.

	gritos.load("gritos.wav");
	golpes.load("golpes.wav");
	risas.load("risas.wav");
	risas.setLoop(loop);
	risas.play();
	gritos.stop();
	gritos.setLoop(false);

	ofGetCurrentTime();

	
}

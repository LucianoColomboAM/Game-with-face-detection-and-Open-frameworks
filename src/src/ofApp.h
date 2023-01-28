// Crearemos la clase Enemigo y terminaremos el juego.

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "Plataforma.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Particulas.h"


using namespace ofxCv;
using namespace cv;


class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);
	void reset();


	bool inicio;
	bool fin;

	float punterox;
	float punteroy;
	float punterox1;
	float punteroy1;
	int dado;

	ofVideoGrabber cam;
	
	ofxCv::ObjectFinder finder;
	ofxCv::ObjectFinder finder2;

	ofxBox2d box2d;
	string texto;
	string bullying1 = "Con apenas 12 anos, Drayke Hardman se quitó la vida tras sufrir bullying.";
	string bullying2 ="El 3 del 11 de 2016 un argentino de 13 años que sufría acoso escolar se mato de un tiro en la cabeza.";
	string bullying3 = "Nicolás Cernadas de 13 años fue encontrado calcinado el pasado lunes 10 de octubre por la tarde en Merlo.";
	string bullying4 = "El 28 de septiembre de 2004 un alumno de 15 años, disparó contra sus compañeros de aula, provocando la muerte de tres de ellos";
	string bullying5 = "20 de abril de 1999 en Columbine, Eric Harris y Dylan Klebold asesinaron a 12 estudiantes y a un profesor.";
	string bullying6 = "El 19 de enero de 2022, en la Academia Oliver Citywide, Marquis Campbell, de 15 años, recibió un disparo en el recinto escolar.";
	string bullying7 = "Respira y concentrate";
	string bullying8 = "Tomate tu tiempo";
	string bullying9 = "Toma el espacio adecuado y controla mejor";
	string bullying10 = "Usa bien tu mente";


	Plataforma piso;
	Plataforma techo[25];


	vector<shared_ptr<Plataforma>> plataformas;	
	Plataforma plataformaExtra;
	Personaje objeto[25];

	

	ofImage marioInicio;
	ofImage fondoInicio;


	ofTrueTypeFont fuenteGrande;
	ofTrueTypeFont fuente;

	ofImage nube;
	ofImage montania;
	ofImage ojo;
	ofImage manos;
	ofImage fondo;

	ofSoundPlayer risas;
	ofSoundPlayer gritos;
	ofSoundPlayer golpes;

	bool loop = true;


	// Creamos los goombas.
	vector<shared_ptr<Enemigo>> goombas;



};

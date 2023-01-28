#include "Particulas.h"

void Particulas::setup(ofxBox2d &box2d, float x, float y)
{
	
	setPhysics(20, 0.5, 3);
	ofxBox2dRect::setup(box2d.getWorld(), x, y, ofRandom(4,10), ofRandom(4,10));
	name = "particula";
	setData(this);
	setFixedRotation(true);
	setVelocity(ofRandom(ofRandom(-1,-10), ofRandom(1, 10)), ofRandom(-3, 3));
	particulaimg.load("explosion.png");
//	ofGetCurrentTime();

}

///////////////////////////////////////////////////////////////////////////
void Particulas::update()
{


	

}

///////////////////////////////////////////////////////////////////////////
void Particulas::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);


	ofSetColor(100, 105, 95, 150);
	particulaimg.draw(getPosition(),ofRandom(15, 40), ofRandom(15, 40));
	//ofDrawRectangle(getPosition(), ofRandom(4, 10), ofRandom(4, 10));
	ofSetColor(255, 255, 255);

	int tiempo = ofGetElapsedTimef();
	if (tiempo % 30 == 0)
	{

		destroy();
		shouldRemoveOffScreen;
		shouldRemove;
	}



	ofSetRectMode(OF_RECTMODE_CORNER);
}

///////////////////////////////////////////////////////////////////////////


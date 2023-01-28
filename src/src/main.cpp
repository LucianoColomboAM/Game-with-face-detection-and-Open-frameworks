#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	// Comentamos esta línea y agregamos las otras para que la aplicación no
	// pueda redimensionarse ni maximizarse.
	/** ofSetupOpenGL(1024,768,OF_WINDOW); */

	// La función ofSetupOpenGL() de oF hace algo parecido a esto pero sin
	// el settings.resizable = false.
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.glVersionMajor = 2;
	settings.glVersionMinor = 1;
	ofCreateWindow(settings);

	ofRunApp(new ofApp());
	
}

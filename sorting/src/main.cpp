#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	int screen_height=GetSystemMetrics(SM_CXSCREEN);
	int screen_width= GetSystemMetrics(SM_CYSCREEN);

	ofSetupOpenGL(screen_height,screen_width,OF_WINDOW);		// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
#include "ofMain.h"
#include "ofApp.h"

int main( ){
	ofGLWindowSettings settings;
	settings.setSize(512, 384);
	settings.title = "Sorting";
	settings.windowMode = OF_WINDOW;
	settings.setPosition(ofVec2f(0, 40));
	
	ofCreateWindow(settings);

	
	ofRunApp(new ofApp());
}
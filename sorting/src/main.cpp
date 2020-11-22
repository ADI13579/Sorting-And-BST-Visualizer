#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	int screen_height=GetSystemMetrics(SM_CXSCREEN);
	int screen_width= GetSystemMetrics(SM_CYSCREEN);
	settings.setSize(screen_height, screen_width);
	settings.title = "Sorting";
	settings.windowMode = OF_WINDOW;
	settings.setPosition(ofVec2f(0, 40));
	ofCreateWindow(settings);

	ofRunApp(new ofApp());
}
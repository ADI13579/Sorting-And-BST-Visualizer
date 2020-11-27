#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	
	int screen_height=GetSystemMetrics(SM_CYSCREEN);
	int screen_width= GetSystemMetrics(SM_CXSCREEN);
	settings.setSize(screen_width, screen_height);
	settings.title = "Sorting";
	settings.windowMode = OF_GAME_MODE;
	settings.setPosition(ofVec2f(0, 40));
	
	ofCreateWindow(settings);

	
	ofRunApp(new ofApp());
}
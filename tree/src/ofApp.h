#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		float array[1000];
		float pos_array[256];
		int index,nodes,max_index;
		int a;

		int get_max();
		void display();
		void insert(float *pos_array,int input,int index);
		int search(int input, int pos,int *search_pos);
		void remove(int input);
	
		ofxPanel panel;
		ofxToggle insertButton,removeButton;
		ofxIntField input;
};
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
		int a,search_pos,exists;

		int get_max();
		void display();
		void insert(int input,int index);
		void search(int input, int pos);
		void remove(int input);
	
		ofxPanel panel;
		ofxToggle insertButton,removeButton,searchButton;
		ofxIntField input;
};
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		float array[1024];
		float pos_array[1024];
		int index,nodes,max_index;
		int search_pos,exists;

		int get_max();
		void insert(int input,int index);
		int search(int input, int pos,int *search_pos);
		void remove(int input);
		void reset();


		string st[2];
		ofTrueTypeFont font;
		ofxPanel panel;
		ofxToggle insertButton,removeButton,searchButton;
		ofxIntField input;
};
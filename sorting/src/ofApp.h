#pragma once

#include "ofMain.h"
#include"ofxGui.h"
#include "dat.h"
#include"rectOperate.h"
#include"sort.h"


class ofApp : public ofBaseApp {
	private:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void insertData();
		void shuffle();


		bubblesort *bubble_sort;
		selectionsort* selection_sort;
		insertionsort* insertion_sort;
		mergesort* merge_sort;

		string st[7];

	
		bool menu,bool_bubble_sort,bool_selection_sort,bool_insertion_sort,bool_merge_sort;
		bool prev_bool_bubble_sort,prev_bool_selection_sort,prev_bool_insertion_sort,prev_bool_merge_sort;

		dat *array;
		float span,width;
		ofVec2f move;
		int number, setColor[3];
		ofVec2f scale;
		rectOperate* animate;

		//Panel to take input of number in menu
		ofxPanel gui;
		ofxIntField intField;
		ofTrueTypeFont font;

		//Panel after menu for sorting
		ofxPanel gui2;
		ofxToggle button;
		ofxIntSlider factor;
};
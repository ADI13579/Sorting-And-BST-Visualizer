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
		void shuffle();//swaps datas with randomly


		bubblesort *bubble_sort;
		selectionsort* selection_sort;
		insertionsort* insertion_sort;
		mergesort* merge_sort;

		string st[7];//just stores some string displayed in menu and inside sorting

		bool menu;
		bool bool_bubble_sort,bool_selection_sort,bool_insertion_sort,bool_merge_sort;//handles the event for sorting type
		bool prev_bool_bubble_sort,prev_bool_selection_sort,prev_bool_insertion_sort,prev_bool_merge_sort;//stores the previous state of events of sorting

		dat *array;
		float span,width,height;

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
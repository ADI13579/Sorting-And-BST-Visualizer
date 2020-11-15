#pragma once

#include "ofMain.h"
#include"ofxGui.h"
#include "dat.h"
#include"rectOperate.h"
#include<stack>


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	

	void keyPressed(int key);
	
	
	void selection_sort_operation(dat* array);
	void selection_sort(dat* array);

	void bubble_sort_operation(dat *array);
	void bubble_sort(dat* array);

	void insertion__sort_operation(dat* array);
	void insertion_sort(dat* array);

	void merge__sort_operation(dat* array);
	void merge_sort(dat* array);
	void set_merge_order(stack<int> *merge_order,int left,int right);
	stack<int> merge_order;


	void shuffle();
	
	int ii,j,count,pos,pos2;

	
	string st[6];
	bool event,menu;
	bool event1, event2, event3;
	bool bool_bubble_sort,bool_selection_sort,bool_insertion_sort,bool_merge_sort;
	
	dat *array;
	int span;
	ofVec2f move;
	int number;
	ofVec2f scale;
	float width;
	rectOperate* animate;
	int setColor[3] ;
	ofxPanel gui;
	ofxIntField intField;
	ofTrueTypeFont font;

	ofxPanel gui2;
	ofxToggle button;
	ofxIntSlider factor;



	bool test;
};
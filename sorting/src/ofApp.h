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
	
	
	void selection_sort_operation();
	void selection_sort();

	void bubble_sort_operation();
	void bubble_sort();

	void insertion__sort_operation();
	void insertion_sort();

	void merge__sort_operation();
	void merge_sort();
	void set_merge_order(stack<int> *merge_order,int left,int right);
	void swap(dat *array1,dat *array2);
	stack<int> merge_order;
	int merge_begin, merge_end;


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

	//Panel to take input of number in menu
	ofxPanel gui;
	ofxIntField intField;
	ofTrueTypeFont font;

	//Panel after menu for sorting
	ofxPanel gui2;
	ofxToggle button;
	ofxIntSlider factor;
};
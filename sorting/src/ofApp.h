#pragma once

#include "ofMain.h"
#include"ofxGui.h"
#include "dat.h"
#include"rectOperate.h"
#include<stack>

class bubblesort
{
	public:
		ofxToggle* button;
		bool event;
		int* setColor;
		dat* array;
		int j,count,pos,number;
		rectOperate* animate;
		ofxIntSlider* factor;
	
		bubblesort(dat* _array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button,ofxIntSlider *_factor)
		{
			number = _number;
			pos = number-1;
			count = 0;
			j = -1;
			array = _array;
			event = 0;
			animate = _animate;
			button = _button;
			setColor = _setColor;
			factor = _factor;
			setColor[0] = setColor[1] = setColor[2] = -1;
		}
		void bubble_sort_operation();
		bool bubble_sort();
};

class selectionsort
{
	public:
		ofxToggle* button;
		bool event;
		int* setColor;
		dat* array;
		int j, count, pos, number;
		rectOperate* animate;
		ofxIntSlider* factor;

		selectionsort(dat *_array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button, ofxIntSlider* _factor)
		{
			number = _number;
			pos= 0;
			count = 0;
			j = -1;
			array = _array;
			event = 0;
			animate = _animate;
			button = _button;
			setColor = _setColor;
			factor = _factor;
			setColor[0] = setColor[1] = setColor[2] = -1;
		}

		void selection_sort_operation();
		bool selection_sort();
		
};

class insertionsort
{
	public:
		ofxToggle* button;
		bool event1,event2,event3;
		int* setColor;
		dat* array;
		int count, pos, number;
		rectOperate* animate;
		ofxIntSlider* factor;

		insertionsort(dat* _array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button, ofxIntSlider* _factor)
		{
			number = _number;
			pos = 1;
			count = 0;
			array = _array;
			event1=event2=event3 = 0;
			animate = _animate;
			button = _button;
			setColor = _setColor;
			factor = _factor;
			setColor[0] = setColor[1] = setColor[2] = -1;
		}
		void insertion__sort_operation();
		bool insertion_sort();
};

class mergesort
{
	public:
		ofxToggle* button;
		bool event1, event2;
		dat* array,*temp_merge_array;

		stack<int> merge_order;
		int merge_begin, merge_end, index, left, right, merge_mid;

		int number;
		rectOperate* animate;
		ofxIntSlider* factor;

		mergesort(dat* _array, int _number, rectOperate* _animate, ofxToggle* _button, ofxIntSlider* _factor)
		{
			index = right = left = 0;
			merge_begin = merge_end = merge_mid = -1;
			number = _number;
			array = _array;
			event1 = 1;
			event2 = 0;
			animate = _animate;
			button = _button;
			factor = _factor;

			temp_merge_array = new dat[number];
			set_merge_order(&merge_order, 0, number - 1);
			stack_rev(&merge_order);
			for (int i = 0; i < number; i++)
				temp_merge_array[i] = array[i];
		}

		void merge_sort();
		void set_merge_order(stack<int>* merge_order, int left, int right);
		void stack_rev(stack<int>* order);
		

};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void shuffle();


	bubblesort *bubble_sort;
	selectionsort* selection_sort;
	insertionsort* insertion_sort;
	mergesort* merge_sort;



	
	string st[7];
	bool menu;
	
	bool bool_bubble_sort,bool_selection_sort,bool_insertion_sort,bool_merge_sort;
	bool prev_bool_bubble_sort,prev_bool_selection_sort,prev_bool_insertion_sort,prev_bool_merge_sort;

	dat *array;
	float span;
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
#pragma once
#include"ofxGui.h"
#include"dat.h"
#include"ofMain.h"
#include"rectOperate.h"
#include<stack>

class bubblesort
{
private:
	ofxToggle* button;
	bool event;
	int* setColor;
	dat* array;
	int j, count, pos, number;
	rectOperate* animate;
	ofxIntSlider* factor;
	void bubble_sort_operation();

public:
	bubblesort(dat* _array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button, ofxIntSlider* _factor)
	{
		number = _number;
		pos = number - 1;
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
	bool bubble_sort();
};

class selectionsort
{
private:
	ofxToggle* button;
	bool event;
	int* setColor;
	dat* array;
	int j, count, pos, number;
	rectOperate* animate;
	ofxIntSlider* factor;
	void selection_sort_operation();

public:
	selectionsort(dat* _array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button, ofxIntSlider* _factor)
	{
		number = _number;
		pos = 0;
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

	bool selection_sort();

};

class insertionsort
{
private:
	ofxToggle* button;
	bool event1, event2, event3;
	int* setColor;
	dat* array;
	int count, pos, number;
	rectOperate* animate;
	ofxIntSlider* factor;
	void insertion__sort_operation();

public:
	insertionsort(dat* _array, int _number, rectOperate* _animate, int* _setColor, ofxToggle* _button, ofxIntSlider* _factor)
	{
		number = _number;
		pos = 1;
		count = 0;
		array = _array;
		event1 = event2 = event3 = 0;
		animate = _animate;
		button = _button;
		setColor = _setColor;
		factor = _factor;
		setColor[0] = setColor[1] = setColor[2] = -1;
	}
	bool insertion_sort();
};

class mergesort
{
private:
	ofxToggle* button;
	bool event1, event2;
	dat* array, * temp_merge_array;

	stack<int> merge_order;

	int number, left, right;
	rectOperate* animate;
	ofxIntSlider* factor;
	void set_merge_order(stack<int>* merge_order, int left, int right);
	void stack_rev(stack<int>* order);

public:
	int merge_begin, merge_end, index, merge_mid;
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
	bool merge_sort();
};
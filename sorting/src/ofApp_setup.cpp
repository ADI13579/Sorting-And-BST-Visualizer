#include "ofApp.h"
//------------------------------------------------------------------------
void ofApp::setup() 
{
	span = (int)(4.5*factor);
	filesystem::path p = "../data/font1.ttf";
	gui.setDefaultHeight(38);
	gui.setDefaultWidth(400);
	intField.setBackgroundColor(ofColor(2500, 0, 0));
	gui.setup();
	
	gui.add(intField.setup("Add Number of Data", number));
	gui2.setup();
	gui2.add(button.setup("Press to start/pause", 0, 400, 40));;
	gui2.add(factor.setup("Slide right to increase speed",1,1,100,400,40)); 
	gui2.setPosition(ofGetWidth() / 2 - gui.getWidth() / 2, 0);

	scale = {(float) ofGetWidth() / (number + 1) ,(float)ofGetHeight() / (2 * (number + 1)) };
	width = scale.x * 70 / 100; //70% is the width of bar
	move = { (float)ofGetWidth() / 2,(float)ofGetHeight() / 2 };

	font.load(p,32);
	st[0] = "Press 1 for Bubble Sort";
	st[1] = "Press 2 for Selection Sort";
	st[2] = "Press 3 for Insertion Sort";
	st[3] = "Press 4 for Merge sort";
	st[4] = "Press R to interupt/shuffle";
	st[5] = "Press M to return to menu";
	st[6] = "Enter Data First";
	menu = 1;

	bool_bubble_sort=bool_selection_sort=bool_insertion_sort=bool_merge_sort=0;
	animate = new rectOperate(&span, move, scale, number);

	array = new dat[number];
	for (int i = 0; i < number; i++)
		array[i].dat = i + 1;

	shuffle();
	
}

void ofApp::shuffle()
{	
	button = 0;
	event = event1 = event2 = event3 = 0;
	ii = number;
	pos2 = 1;
	index=right=left=count = pos = 0;
	merge_begin = merge_end = merge_mid = -1;
	j = -1;
	setColor[2] = setColor[1] = setColor[0] = -1;


	for (int i = 0; i < number; i++)
	{
		int swap1 = (int)ofRandom(number);
		int swap2 = (int)ofRandom(number);

		int temp = array[swap1].dat;

		array[swap1].dat = array[swap2].dat;
		array[swap2].dat = temp;
	}

	for (int i = 0; i < number; i++)
	{
		array[i].size = { width,(array[i].dat * scale.y) };
		array[i].pos = { (scale.x * (i + 1)),(float)(ofGetHeight() - array[i].size.y) };
		array[i].xpos = array[i].pos.x;
	};
	if (bool_merge_sort)
	{
		event1 = 1;
		merge_setup();
	}
}
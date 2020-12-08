#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::update() {
	span = 5 * factor;
	height = ofGetHeight();
	if (button)
	{
		if (bool_bubble_sort)
		{
			prev_bool_bubble_sort = bool_bubble_sort;
			bool_bubble_sort=bubble_sort->bubble_sort();
		}
		if (bool_selection_sort)
		{
			prev_bool_selection_sort = bool_selection_sort;
			bool_selection_sort=selection_sort->selection_sort();
		}
		if (bool_insertion_sort)
		{
			prev_bool_insertion_sort = bool_insertion_sort;
			bool_insertion_sort=insertion_sort->insertion_sort();
		}
		if (bool_merge_sort)
		{
			prev_bool_merge_sort = bool_merge_sort;
			bool_merge_sort=merge_sort->merge_sort();
		}
	}
	if (intField!=number)
	{
		if (intField > 10)
			number = intField;
		else
			intField = number = 10;
		free(array);
		free(animate);//scale depends on the greatest data so animate is again created when numbers are increased
		insertData();
	}
}


//--------------------------------------------------------------
void ofApp::draw()
{
	if (menu)
	{
		font.drawString(st[6], (ofGetWidth() / 2 - font.stringWidth(st[6]) / 2),40);
		gui.setPosition(ofGetWidth() / 2 - gui.getWidth() / 2,42);
		gui.draw();
		
		for(int i=0;i<4;i++)
			font.drawString(st[i], (ofGetWidth()/2-font.stringWidth(st[i])/2),(4+i)*40);
	}
	else
	{
		gui2.draw();
		font.drawString(st[4], (ofGetWidth() / 2 - font.stringWidth(st[4]) / 2),170);
		font.drawString(st[5], (ofGetWidth() / 2 - font.stringWidth(st[5]) / 2), 210);
		
			for (int i = 0; i < number; i++)
			{
				if (!bool_merge_sort)
				{
					if (i == setColor[0] || i == setColor[1] || i == setColor[2])
						ofSetColor(242, 60, 112);
					else
						ofSetColor(145, 224, 215);
				}
				else
				{
					if (merge_sort->setColor[i] == 0)
					{
						ofSetColor(229, 234, 75);
					}
					else if (merge_sort->setColor[i]==1)
						ofSetColor(237, 124, 99);
					else if(merge_sort->setColor[i]==2)
						ofSetColor(145,224,215);
				}
				ofDrawRectangle(array[i].pos, array[i].size.x, array[i].size.y);
			}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	if (key == '1' && menu)
	{
		menu = 0;
		bubble_sort = new bubblesort(&array[0], number,animate,&setColor[0],&button,&factor);
		bool_bubble_sort =prev_bool_bubble_sort= 1;
	}
	else if (key == '2' && menu)
	{
		menu = 0;
		bool_selection_sort =prev_bool_selection_sort= 1;
		selection_sort = new selectionsort(&array[0], number, animate, &setColor[0], &button, &factor);
	}
	else if (key == '3' && menu)
	{
		menu = 0;
		bool_insertion_sort = prev_bool_insertion_sort=1;
		insertion_sort= new insertionsort(&array[0], number, animate, &setColor[0], &button, &factor);
	}
	else if (key == '4' && menu)
	{
		menu = 0;
		merge_sort = new mergesort(&array[0], number, animate, &button, &factor);
		bool_merge_sort =prev_bool_merge_sort=1;
	}
	else if (key == 'r' && menu != 1)
	{
		shuffle();
		if (prev_bool_bubble_sort)
		{
			bool_bubble_sort = 1;
			free(bubble_sort);
			bubble_sort = new bubblesort(&array[0], number, animate, &setColor[0], &button, &factor);
		}
		else if(prev_bool_selection_sort)
		{
			bool_selection_sort = 1;
			free(selection_sort);
			selection_sort = new selectionsort(&array[0], number, animate, &setColor[0], &button, &factor);
		}
		else if (prev_bool_insertion_sort)
		{
			bool_insertion_sort = 1;
			free(insertion_sort);
			insertion_sort = new insertionsort(&array[0], number, animate, &setColor[0], &button, &factor);
		}
		else if(prev_bool_merge_sort)
		{
			bool_merge_sort = 1;
			free(merge_sort);
			merge_sort = new mergesort(&array[0], number, animate, &button, &factor);
		}
	}
	else if (key == 'm')
	{
		shuffle();
		if (prev_bool_bubble_sort)
			free(bubble_sort);
		else if (prev_bool_insertion_sort)
			free(insertion_sort);
		else if (prev_bool_selection_sort)
			free(selection_sort);
		
		bool_selection_sort = bool_bubble_sort = bool_insertion_sort=bool_merge_sort = 0;
		prev_bool_selection_sort =prev_bool_bubble_sort =prev_bool_insertion_sort=prev_bool_merge_sort = 0;
		menu = 1;
	}
}
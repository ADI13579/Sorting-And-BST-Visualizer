#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::update() {
	span = 5 * factor;
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
			merge_sort->merge_sort();
		}
	}
	if (intField > number)
	{
		number = intField;
		free(array);
		free(animate);
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
					int merge_begin = merge_sort->merge_begin;
					int merge_mid = merge_sort->merge_mid;
					int merge_end = merge_sort->merge_end;

					if (i > merge_mid&& i <= merge_end)
						ofSetColor(229, 234, 75);
					else if (i >= merge_begin && i <= merge_mid)
						ofSetColor(237, 124, 99);
					else
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
		if (prev_bool_bubble_sort)
			free(bubble_sort);
		else if (prev_bool_selection_sort)
			free(selection_sort);
		else if (prev_bool_insertion_sort)
			free(insertion_sort);
		else if (prev_bool_merge_sort)
			free(merge_sort);
		bool_selection_sort = bool_bubble_sort = bool_insertion_sort = 0;
		prev_bool_selection_sort =prev_bool_bubble_sort =prev_bool_insertion_sort = 0;
		menu = 1;
	}
}
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::update() {
	span = 5 * factor;
	if (button)
	{
		if (bool_bubble_sort)
		{
			bubble_sort();
		}
		if (bool_selection_sort)
		{
			selection_sort();
		}
		if (bool_insertion_sort)
		{
			insertion_sort();
		}
		if (bool_merge_sort)
		{
			merge_sort();
		}
	}
	
	if (intField > 0 && intField != number)
	{
			number = intField;
			setup();
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
		
		//if (bool_merge_sort)
		//{
		//	int temp = -1;
		//	ofVec3f color[3];
		//	color[0].x = 121; color[0].y = 103; color[0].z = 224;
		//	color[1].x = 182; color[1].y = 226; color[1].z = 61;
		//	color[2].x = 226; color[2].y = 61; color[2].z = 174;
		//	stack<int> temp_set_color=set_color;
		//	cout << "displaying   :";
		//	display(set_color);
		//	cout << endl;
		//	for (int i = 0; i < number; i++)
		//	{
		//		if (i == setColor[0] || i == setColor[1] || i == setColor[2])
		//			ofSetColor(242, 60, 112);
		//		else
		//			ofSetColor(145, 224, 215);
		//		ofDrawRectangle(array[i].pos, array[i].size.x, array[i].size.y);
		//	}

		//		/*while (temp_set_color.top() < number - 1)
		//		{
		//			cout << "Running"<<endl;
		//			temp=temp++%3;
		//			int a = temp_set_color.top();
		//			temp_set_color.pop();
		//			for (int i = a; i < set_color.top(); i++)
		//			{
		//				ofSetColor(color[temp].x, color[temp].y, color[temp].z);
		//				ofDrawRectangle(array[i].pos, array[i].size.x, array[i].size.y);
		//			}
		//		}*/
		//}
		//else
		{
			for (int i = 0; i < number; i++)
			{
				if (i == setColor[0] || i == setColor[1] || i == setColor[2])
					ofSetColor(242, 60, 112);
				else
					ofSetColor(145, 224, 215);
				ofDrawRectangle(array[i].pos, array[i].size.x, array[i].size.y);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	if (key == '1' && menu)
	{
		menu = 0;
		bool_bubble_sort = 1;
	}
	if (key == '2' && menu)
	{
		menu = 0;
		bool_selection_sort = 1;
	}
	if (key == '3' && menu)
	{
		menu = 0;
		bool_insertion_sort = 1;
	}
	if (key == '4' && menu)
	{
		menu = 0;
		merge_setup();
		bool_merge_sort = event1=1;
	}
	else if (key == 'r' && menu!=1)
	{
		shuffle();
	}
	else if (key == 'm')
	{
		setup();
		menu = 1;
		bool_selection_sort = bool_bubble_sort = bool_insertion_sort = 0;
	}
}
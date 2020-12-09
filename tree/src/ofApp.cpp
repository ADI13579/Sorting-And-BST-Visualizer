#include "ofApp.h"

void ofApp::display()
{
	int height = log2(max_index);
	int p = 100, k = 1;
	int add = 0;

	for (int i = 1; i <= max_index; i++)
	{
		if (i == pow(2, k) - 1)
		{
			ofDrawCircle(ofVec2f(ofGetWidth() / (pow(2, k) * (k % i)), k * 100), 50);
			k++;
		}
	}
}
int ofApp::get_max()
{
	int temp = pow(2, nodes);
	if (temp > 1000)
		temp = 999;
	while (array[temp] == -1)
	{
		temp--;
	}
	return temp;
}
void ofApp::insert(float *array,int input, int index,int *insertedat)
{
	if (index < 1000)
	{
		if (array[index] == -1)
		{
			nodes++;
			array[index] = input;
			*insertedat = index;
			max_index = get_max();
			return;
		}
		else if (input > array[index])
			insert(array,input, 2 * index + 1,insertedat);
		else if (input < array[index])
			insert(array,input, 2 * index,insertedat);
		else if (array[index] == input)
			return;
	}
}

int ofApp::search(int input, int pos,int *search_pos)
{
	if (pos < 500)
	{
		if (input == -1)
			return -1;
		else if (input > array[pos])
			search(input, 2 * pos + 1,search_pos);
		else if (input < array[pos])
			search(input, 2 * pos,search_pos);
		else if (array[pos] == input)
		{
			*search_pos=pos;
		}
	}
}


void ofApp::remove(int input)
{
	int search_pos=0,temp=0,insertedat=0;
	search(input, 1,&search_pos);
	if (search_pos!= -1 && search_pos!=0 && search_pos<500);
	{
		nodes--;
		if (array[2 * search_pos] == -1 && array[2 * search_pos + 1] == -1)
			array[search_pos] = -1;
		else if (array[2 * search_pos] != -1 && array[2 * search_pos + 1] != -1)
		{
			temp = 2 * search_pos + 1;
			while (array[2 * temp] != -1)
			{
				temp*=2;
			}
			
			int copy = array[temp];
			remove(array[temp]);
			array[search_pos] = copy;
		}
		else if (array[2 * search_pos] == -1 && array[2 * search_pos + 1] != -1)
		{
			array[search_pos] = array[2 * search_pos + 1];
			array[2 * search_pos + 1] = -1;

			for (int i = search_pos * 2 + 2; i <=max_index; i++)
			{
				if (array[i] != -1)
				{
					insert(&array[0],array[i], 1, &insertedat);
					array[i] = -1;
				}
			}
		}
		else if (array[2 * search_pos] != -1 && array[2 * search_pos + 1] == -1)
		{
			array[search_pos] = array[2 * search_pos];
			array[2 * search_pos] = -1;
			for (int i = 2*search_pos; i <= max_index; i++)
			{
				if (array[i] != -1)
				{
					insert(&array[0],array[i], 1, &insertedat);
					array[i] = -1;
				}
			}
		}
		max_index = get_max();
	}
}
//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < 1000; i++)
		array[i] = -1;
	
	pos_array[0] = -1;

	for (int i = 1; i < 8; i++)
	{
		for (int j = pow(2, i - 1),k=1; j < pow(2, i); j++,k+=2)
		{
			pos_array[j]=k*ofGetWidth()/ (pow(2,i));
		}
	}


	index = nodes=max_index=0;
	input = -1;

	panel.setup();
	panel.add(input.setup("Enter Data", input));
	panel.add(insertButton.setup("Press to insert", insertButton));
	panel.add(removeButton.setup("Press to remove", removeButton));
	insertButton = removeButton = 0;


	//int lo;
	//insert(&array[0], 47, 1, &lo);
	//insert(&array[0], 24, 1, &lo);
	//insert(&array[0], 21, 1, &lo);
	//insert(&array[0], 25, 1, &lo);
	//insert(&array[0], 48, 1, &lo);
	//insert(&array[0], 49, 1, &lo);
}

//--------------------------------------------------------------
void ofApp::update(){
	int insertedat;
	index = 1;
	if (insertButton && input!=-1)
	{
		insert(&array[0],input,1,&insertedat);
		insertButton = 0;
		
		
	}
	if (removeButton && input!=-1)
	{
		remove(input);
		removeButton = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	panel.draw();
	int span = 100,j=1;
	
	int k = 1;
	int add = 0;

	for (int i = 1; i <= max_index; i++)
	{
		if (array[2 * i] != -1)
		{
			ofDrawLine(ofVec2f(pos_array[i], k * 100), ofVec2f(pos_array[2 * i], (k + 1) * 100));
		}
		if (array[2 * i+1] != -1)
		{
			ofDrawLine(ofVec2f(pos_array[i], k * 100), ofVec2f(pos_array[2 * i+1], (k + 1) * 100));
		}
		if (array[i] != -1)
		{
			ofSetColor(163, 119, 147);
			ofDrawCircle(ofVec2f(pos_array[i], k * 100), 50);
			ofSetColor(0, 0, 0);
			ofDrawBitmapString(array[i], pos_array[i]-25, k * 100);
		}
		if (i == pow(2, k) - 1)
		{
			k++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r')
		setup();
}
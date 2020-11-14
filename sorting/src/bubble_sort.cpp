#include"ofApp.h"


void ofApp::bubble_sort_operation(dat* array)
{
	setColor[0] = j;
	setColor[1] = -1;
	this_thread::sleep_for(chrono::milliseconds((int)(500-5*factor)));//y=mx+c where m=-5,c=500
	if (array[j].dat > array[j + 1].dat)
	{
		setColor[1] = j + 1;
		event = 1;
	}
	else
	{
		setColor[0] = j;
		event = 0;
	}
}

void ofApp::bubble_sort(dat* array)
{
	if (event)
	{
		event = animate->rectOperationSwap(&array[j], &array[j + 1]);
	}
	else
	{
		if (j == ii - 2)
		{
			j = 0;
			ii--;
			count++;
		}
		else
			j++;
		if (count == number - 1)
		{
			j = 0;
			button = 0;
			setColor[0] = setColor[1] = -1;
		}

		bubble_sort_operation(array);
	}
}
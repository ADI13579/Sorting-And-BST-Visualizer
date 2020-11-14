#include"ofApp.h"


void ofApp::selection_sort_operation(dat* array)
{
	setColor[0] = count;
	setColor[1] = pos;
	setColor[2] = j;

	if (array[j].dat <array[pos].dat)
	{
		pos = j;
	}
	if (j == number - 1 && count!=pos)
	{
		event = 1;
	}
}

void ofApp::selection_sort(dat*array)
{
	if (event)
	{
		setColor[2] = -1;
		event = animate->rectOperationSwap(&array[count], &array[pos]);
	}
	else
	{
		if (j == number - 1)
		{
			count++;
			j = count;
			pos = j;
		}
		else
			j++;
		if (count == number - 1)
		{
			button = 0;
		}
		this_thread::sleep_for(chrono::milliseconds((int)(500 - 5 * factor)));//y=mx+c where m=-5,c=500
		selection_sort_operation(array);
	}
}
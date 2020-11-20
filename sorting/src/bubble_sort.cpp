#include"ofApp.h"

void bubblesort::bubble_sort_operation()
{
	setColor[0] = j;
	setColor[1] = -1;
	this_thread::sleep_for(chrono::milliseconds((int)(500-5*(*factor))));//y=mx+c where m=-5,c=500
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

bool bubblesort::bubble_sort()
{
	if (event)
	{
		event = animate->rectOperationSwap(&array[j], &array[j + 1]);
	}
	else
	{
		if (j == pos - 1)
		{
			j = 0;
			pos--;
			count++;
		}
		else
			j++;
		if (count == number - 1)
		{
			j = 0;
			button = 0;
			setColor[0] = setColor[1] = -1;
			return 0;
		}

		bubble_sort_operation();
	}
	return 1;
}
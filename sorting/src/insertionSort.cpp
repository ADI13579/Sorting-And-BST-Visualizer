#include"sort.h"


void insertionsort::insertion__sort_operation()
{
	if (array[pos].dat < array[pos-1].dat && pos!=0)
	{
		if (array[pos].pos.y < ofGetHeight() / 2)
		{
			event2 = 1;
			event3 = event1 = 0;
		}
		else
		{
			event1 = 1;
		}
	}
	else if(array[pos].dat >= array[pos - 1].dat || pos == 0)
	{
		event3 = 1;
	}
	this_thread::sleep_for(chrono::milliseconds((int)(120 -  2* (*factor))));//y=mx+c where m=-2,c=120
}

bool insertionsort::insertion_sort()
{
	if (event1 || event2 || event3)
	{
		if (event1)
		{
			event1 = animate->moveUp(&array[pos]);
			setColor[0] = pos;
			if (!event1)
			{
				setColor[1]= pos-1;
			}
		}

		if (event2)
		{
			event2 = animate->rectSwap(&array[pos], &array[pos - 1]);
			if (event2 == 0)
			{
				pos--;
				setColor[0] = pos;
				setColor[1] = pos - 1;
			}
		}

		if (event3)
		{
			setColor[1] = -1;
			event3 = animate->moveDown(&array[pos]);
			if (event3 == 0)
			{
				i++;
				pos = i;
			} 
		}
	}
	else
	{
		setColor[0] = pos;
		if (i > number-1)
		{
			button = 0;
			return 0;
		}
		else
			insertion__sort_operation();
	}
	return 1;
}
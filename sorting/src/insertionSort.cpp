#include"ofApp.h"


void ofApp::insertion__sort_operation()
{
	if (array[pos2].dat >= array[pos2 - 1].dat || pos2 == 0)
	{
		this_thread::sleep_for(chrono::milliseconds((int)(500 - 5 * factor)));//y=mx+c where m=-0.2,c=500
		event3 = 1;
	}

	if (array[pos2].dat < array[pos2-1].dat && pos2!=0)
	{
		if (array[pos2].pos.y < ofGetHeight() / 2)
		{
			event2 = 1;
			event3 = event1 = 0;
		}
		else
		{
			event1 = 1;
		}
	}	
}
void ofApp::insertion_sort()
{
	if (event1 || event2 || event3)
	{
		if (event1)
		{
			event1 = animate->moveUp(&array[pos2]);
			setColor[0] = pos2;
			setColor[1] = -1;
		}


		if (event2)
		{
			event2 = animate->rectSwap(&array[pos2], &array[pos2 - 1]);
			if (event2 == 0)
			{
				pos2--;
				setColor[0] = pos2;
				setColor[1] = pos2 - 1;
			}
		}

		if (event3)
		{
			setColor[1] = -1;
			event3 = animate->moveDown(&array[pos2]);
			if (event3 == 0)
			{
				count++;
				pos2 = count;
			} 
		}
	}
	else
	{
		setColor[0] = pos2;
		if (count == number)
			button= 0;
		else
			insertion__sort_operation();
	}
}
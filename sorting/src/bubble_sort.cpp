#include"sort.h"

void bubblesort::bubble_sort_operation()
{
	setColor[0] = j;
	setColor[1] = -1;
	std::this_thread::sleep_for(chrono::milliseconds((int)(300-5*(*factor))));//y=mx+c where m=-5,c=500
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
			i++;
		}
		else
			j++;
		if (i == number - 1)
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

/*working
event controls the animation of the rectangle to swap and gets updated itself when completes
event=1 begins the rectangle swap operation and data is swapped in rectSwap which is a part of rectOperationSwap

void bubblesort(int *array,int length)
{
	for(int i=0;i<length;i++)
	{
		for(int j=1;j<length-i;j++)
		{
			if(array[j-1]>array[j])
			{
				int temp=array[j-1];
				array[j-1]=array[j];
				array[j]=temp;;
			}
		}
	}
}
*/
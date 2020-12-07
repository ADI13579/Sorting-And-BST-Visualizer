#include"sort.h"

bool mergesort::merge_sort()
{
		if (event1)
		{
			if (merge_begin==-1 && merge_end== -1)
				event1 = 0;
			else
			{
				for (int i = merge_begin; i <= merge_end; i++)
				{
					event1 = animate->moveDown(&array[i]);
				}
			}
			if (!event1)
			{
				if (merge_begin == 0 && merge_end!=number-1 && setColor[merge_begin] == setColor[merge_end + 1])
					setColor[merge_begin] = setColor[merge_end + 1]+1;

				
				if (merge_begin != 0 && merge_end != number - 1)
				{
					if (setColor[merge_begin - 1] == 0)
					{
						if (setColor[merge_end + 1] == 1)
							setColor[merge_begin] = 2;
						if (setColor[merge_end + 1] == 2)
							setColor[merge_begin] = 1;
					}

					if (setColor[merge_begin - 1] == 1)
					{
						if (setColor[merge_end + 1] == 0)
							setColor[merge_begin] = 2;
						if (setColor[merge_end + 1] == 2)
							setColor[merge_begin] = 0;
					}

					if (setColor[merge_begin - 1] == 2)
					{
						if (setColor[merge_end + 1] == 0)
							setColor[merge_begin] = 1;
						if (setColor[merge_end + 1] == 1)
							setColor[merge_begin] = 0;
					}

				}
				
				setColor[merge_begin] %= 3;

				for (int i = merge_begin; i <= merge_end; i++)
				{
					array[i] = temp_merge_array[i];
					setColor[i] = setColor[merge_begin];
				}
				if (merge_order.empty())
				{
					button = 0;
					return 0;
				}
				else
				{
					index = left = merge_begin = merge_order.top();
					merge_order.pop();
					merge_end = merge_order.top();
					merge_order.pop();
					merge_mid = (merge_begin + merge_end) / 2;
					right = merge_mid + 1;
					event2 = 1;
				}
			}
		}
		if (event2)
		{

			if (((array[left].dat < array[right].dat &&left<merge_mid+1)) ||(right==merge_end+1 && left<merge_mid+1))
			{
				event2 = animate->moveTo(&array[left], index, temp_merge_array);
				if (!event2)
				{
					index++;
					left++;
				}
			}
			else if ((array[right].dat < array[left].dat && right<merge_end+1)||(left==merge_mid+1 && right<merge_end+1))
			{
				event2 = animate->moveTo(&array[right], index, temp_merge_array);
				if (!event2)
				{
					index++;
					right++;
				}
			}
			if (left >= merge_mid + 1 && right >= merge_end + 1)
			{
				event1 = 1;
			}
			else
			{
				event2 = 1;
			}
		}
		return 1;
}

void mergesort::set_merge_order(stack<int>* merge_order,int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		set_merge_order(merge_order, left, mid);
		set_merge_order(merge_order, mid + 1, right);
		merge_order->push(left);
		merge_order->push(right);
	}
}


void mergesort::stack_rev(stack<int> *order)
{
	stack<int> temp1;
	while (!order->empty())
	{
		temp1.push(order->top());
		order->pop();
	}
	*order = temp1;
}
/*
the function set_merge_order does only the recursion part to store the order how the dividing occurs and stores it in a stack and again reverses it in the same stack


event1=1 moves every rectangle to the bottom && assigns the value to merge_begin and merge_end and copies the elements of
temp array back to original array;

event2=1 starts the merge and assigns event1=1 after completion;

void mergesort(int *array,int left,int right)
{
	int mid=(left+right)/2;
		int j=left,k=mid+1;
	if(left<mid)
	{
		mergesort(&array[0],left,mid);
		mergesort(&array[0],mid+1,right);
	}

	int *temp_array=new int[right-left+1];
	for(int i=left-left;i<=right-left;i++)
	{
		if((j<mid+1 && array[j]<=array[k])||k==right+1)
		{
			temp_array[i]=array[j];
			j++;
		}
		else if((k<right+1 && array[k]<=array[j])||j==mid+1)
		{
			temp_array[i]=array[k];
			k++;
		}
	}

	for(int i=left;i<=right;i++)
	{
		array[i]=temp_array[i-left];
	}
}
*/
#include"ofApp.h"

void ofApp::merge_sort_operation()
{

}
void ofApp::merge_sort()
{
	if (event1) 
	{
		if (merge_begin == merge_end == merge_mid == -1)
		{
			if (!merge_order.empty())
			{
				index1=merge_begin = merge_order.top(); merge_order.pop();
				merge_end = merge_order.top(); merge_order.pop();
				merge_mid = (merge_begin + merge_end) / 2;
				index2 = merge_mid+1;
			}
		}
		else
		{
			if (index2 == merge_end)
			{

			}
			if (index1 == merge_mid)
			{
				event2 = 1;
			}
			if (index1 == merge_mid && index2 == merge_end)
			{
				event3 = 1;
			}
		}
	}
	if (event2)
	{
		event2= animate->moveTo(array, 5);
		if (!event2)
		{
			temp_merge_array[index] = *array;
			temp_merge_array[index].pos.y = ofGetHeight()-temp_merge_array[index].size.y;
			index++;
			event1 = 1;
		}
	}
	if (event3)
	{
		for (int i = merge_begin; i < merge_end; i++)
		{
			event3 = animate->moveDown(&array[i]);
		}
		if (!event3)
		{
			*array = *temp_merge_array;
			event1 = 1;
		}
	}
}


void ofApp::set_merge_order(stack<int>* merge_order, int left,int right)
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

void ofApp::stack_rev()
{
	stack<int> temp1;
	temp1=merge_order;
	while (!merge_order.empty())
	{
		temp1.push(merge_order.top());
		merge_order.pop();
	}
	merge_order = temp1;
}
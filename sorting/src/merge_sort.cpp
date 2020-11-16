#include"ofApp.h"

void ofApp::merge_sort_operation()
{

}
void ofApp::merge_sort()
{
	if (event1) 
	{
		merge_sort_operation();
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
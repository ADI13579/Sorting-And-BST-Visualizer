#include"ofApp.h"

void ofApp::merge__sort_operation()
{
	
}
void ofApp::merge_sort()
{
	if (event1) 
	{
		event1 = animate->moveTo(&array[merge_begin], merge_end);
		
	}
	else if(!event1 && !merge_order.empty())
	{
		merge_begin = merge_order.top();
		merge_order.pop();
		merge_end = merge_order.top();
		merge_order.pop();
		event1 = animate->moveTo(&array[merge_begin], merge_end);
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
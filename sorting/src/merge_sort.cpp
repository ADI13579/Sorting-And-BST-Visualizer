#include"ofApp.h"

void ofApp::merge__sort_operation(dat* array,int merge_begin,int merge_end)
{

}
void ofApp::merge_sort(dat* array)
{
	if (event) 
	{
		event = animate->moveTo(&array[merge_begin], merge_end);
	}
	else if(!event && !merge_order.empty())
	{
		merge_begin = merge_order.top();
		merge_order.pop();
		merge_end = merge_order.top();
		merge_order.pop();
		event = animate->moveTo(&array[merge_begin], merge_end);
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
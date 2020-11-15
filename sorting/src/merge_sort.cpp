#include"ofApp.h"

void ofApp::merge__sort_operation(dat* array)
{

}
void ofApp::merge_sort(dat* array)
{
	int a=0, b=0;
	if (!event)
	{
		a = merge_order.top();
		merge_order.pop();
		b = merge_order.top();
		merge_order.pop();
		event = animate->moveTo(&array[a], array[b].xpos);
	}
	else
	{
		event= animate->moveTo(&array[a], array[b].xpos);
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
#include"ofApp.h"

void ofApp::merge_sort()
{
		if (event1)
		{
			for (int i = merge_begin; i <= merge_end; i++)
			{
				event1 = animate->moveDown(&array[i]);
			}
			if (merge_begin == -1)
				event1 = 0;
			if (!event1)
			{;
				for (int i = merge_begin; i <= merge_end; i++)
				{
					array[i] = temp_merge_array[i];
				}
				if (merge_order.empty())
				{
					bool_merge_sort = 0;
					button = 0;
					return;
				}
				else
				{
					index = left = merge_begin = merge_order.top();
					merge_order.pop();
					merge_end = merge_order.top();
					merge_order.pop();
					merge_mid = (merge_begin + merge_end) / 2;
					right = merge_mid + 1;
					merge_set_color();
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
}
void ofApp::merge_setup()
{
	while (!merge_order.empty())
	{
		merge_order.pop();
	}
	temp_merge_array = new dat[number];
	set_merge_order(&merge_order, 0, number - 1);
	stack_rev(&merge_order);
	merge_set_color();
	for (int i = 0; i < number; i++)
		temp_merge_array[i] = array[i];
}
void ofApp::set_merge_order(stack<int>* merge_order,int left,int right)
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
void ofApp::merge_set_color()
{
	stack<int> temp = merge_order;
	while (!set_color.empty())
	{
		set_color.pop();
	}
	set_color.push(0);
	while(!temp.empty())
	{
		if (set_color.top() < temp.top())
		{
			set_color.push(temp.top());
		}
		temp.pop();
	}
	stack_rev(&set_color);
}

void ofApp::stack_rev(stack<int> *order)
{
	stack<int> temp1;
	while (!order->empty())
	{
		temp1.push(order->top());
		order->pop();
	}
	*order = temp1;
}
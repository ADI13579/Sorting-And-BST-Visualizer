#include"ofApp.h"

void ofApp::merge_sort_operation()
{

}

void ofApp::merge_sort()
{
	for (int i = 0; i < number; i++)
	{
		cout << temp_merge_array[i].dat<<"   ";
	}
	cout << endl;

		if (event1)
		{
			for (int i = merge_begin; i <= merge_end; i++)
			{
				event1 = animate->moveDown(&array[i]);
			}
			cout << "Running"<<endl;
			if (merge_begin == -1)
				event1 = 0;
			if (!event1)
			{
				for (int i = merge_begin; i <= merge_end; i++)
				{
					array[i] = temp_merge_array[i];
				}
				if (merge_order.empty())
				{
					bool_merge_sort = 0;
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
					cout << "index 1,2" << "  " << left << "   " << right << endl;
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
				cout << "AM i called";
				event2 = animate->moveTo(&array[right], index, temp_merge_array);
				if (!event2)
				{
					index++;
					right++;
				}
			}
			if (left >= merge_mid + 1 && right >= merge_end + 1)
			{
				cout << "event 1 to be calld" << endl;
				event1 = 1;
			}
			else
			{
				event2 = 1;
				cout << "event 2 to be calld" << endl;

			}
		}
}

//void ofApp::merge_sort()
//{
//	if (event1) 
//	{
//		if (merge_begin == merge_end == merge_mid == -1)
//		{
//			if (!merge_order.empty())
//			{
//				left=merge_begin = merge_order.top(); merge_order.pop();
//				merge_end = merge_order.top(); merge_order.pop();
//				merge_mid = (merge_begin + merge_end) / 2;
//				right = merge_mid+1;
//			}
//
//		}
//		else
//		{
//			if (right == merge_end)
//			{
//
//			}
//			if (left == merge_mid)
//			{
//				event2 = 1;
//			}
//			if (left == merge_mid && right == merge_end)
//			{
//				event3 = 1;
//			}
//		}
//	}
//	if (event2)
//	{
//		if (array[right].dat < array[left].dat)
//			event2 = animate->moveTo(&array[right], left);
//		else if (array[right].dat > array[left].dat)
//			event2 = animate->moveTo(&array[left], left);
//		else if (left == merge_mid)
//		{
//			for (int i = right; i < merge_end; i++)
//			{
//				animate->moveTo(&array[],);
//			}
//		}
//		if (!event2)
//		{
//			temp_merge_array[index] = *array;
//			temp_merge_array[index].pos.y = ofGetHeight()-temp_merge_array[index].size.y;
//			index++;
//			event1 = 1;
//		}
//	}
//	if (event3)
//	{
//		for (int i = merge_begin; i < merge_end; i++)
//		{
//			event3 = animate->moveDown(&array[i]);
//		}
//		if (!event3)
//		{
//			*array = *temp_merge_array;
//			event1 = 1;
//		}
//	}
//}


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
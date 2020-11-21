#include"rectOperate.h"

bool rectOperate::rectOperationSwap(dat* array1, dat* array2)
{
	if (a)
	{
		a=moveUp(array1, array2);
		b = !a;
		return 1;
	}
	else if (b)
	{
		b = rectSwap(array1, array2);
		c = !b;
		return 1;
	}
	else if (c)
	{
		c = moveDown(array1, array2);
		if (c == 0)
		{
			a=1;
		}
		return c;
	}
	
	return 0;
}


bool rectOperate::rectOperationShift(dat* array1, dat* array2)
{
	if (a)
	{
		a = moveUp(array1);
		b = !a;
	}
	else if (b)
	{
		b = rectSwap(array1, array2);
		if (b == 0)
		{
			a = 1;
			return 0;
		}
	}
	return 1;
}

bool rectOperate::rectSwap(dat* array1, dat* array2)
{
	if (array1->xpos < array2->xpos)
	{
		array1->pos.x += *span;
		array2->pos.x -= *span;
	}
	else if (array1->xpos > array2->xpos)
	{
		array1->pos.x -= *span;
		array2->pos.x += *span;
	}
	
	if (abs(array1->pos.x - array2->pos.x) >= abs(array1->xpos - array2->xpos))
	{
		dat temp = *array1;
		*array1 = *array2;
		*array2 = temp;
	
		float temp1 = array1->xpos;
		int temp2 = array1->xpos;
		
		array1->pos.x = array2->xpos;
		array1->xpos = array2->xpos;

		array2->pos.x = temp1;
		array2->xpos = temp2;

		return 0;
	}
	return 1;
}

bool rectOperate::moveUp(dat* array1, dat* array2)
{
	if ((array1->pos.y) < move.y - array1->size.y)
	{
		array1->pos.y = move.y - array1->size.y;
		array2->pos.y = move.y - array2->size.y;
		return 0;
	}
	array1->pos.y -= *span;
	array2->pos.y -= *span;
	return 1;
}

bool rectOperate::moveDown(dat* array1, dat* array2)
{
	if (ofGetHeight() - array1->size.y < array1->pos.y)
	{
		array1->pos.y = ofGetHeight() - array1->size.y;
		array2->pos.y = ofGetHeight() - array2->size.y;
		return 0;
	}
	array1->pos.y += *span;
	array2->pos.y += *span;
	return 1;
};
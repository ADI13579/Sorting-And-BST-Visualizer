#include"rectOperate.h"
#include"ofApp.h"


bool rectOperate::moveRight(dat* array, float point_x)
{
	if (array->pos.x >= point_x)
	{
		array->pos.x = point_x;
		array->xpos = point_x;
		return 0;
	}
	array->pos.x += *span;
	return 1;
}

bool rectOperate::moveLeft(dat* array, float point_x)
{
	if (array->pos.x < point_x)
	{
		array->pos.x = point_x;
		array->xpos = point_x;
		return 0;
	}
	array->pos.x -= *span;
	return 1;
}


bool rectOperate::moveUp(dat* array)
{
	if (array->pos.y > move.y - array->size.y)
	{
		array->pos.y -= *span;
		return 1;
	}
	array->pos.y = move.y - array->size.y;
	return 0;
}

bool rectOperate::moveDown(dat* array)
{
	if ((ofGetHeight() - array->size.y )< array->pos.y)
	{
		array->pos.y = ofGetHeight() - array->size.y;
		return 0;
	}
	array->pos.y += *span;
	return 1;
}

bool rectOperate::moveTo(dat* array, int index, dat* temp_merge_array)
{
	bool  b = 0;
	float x = (index + 1) * scale.x;
	if (array->xpos > x)
	{
		*span = *span/7;
		b = moveLeft(array, x);
	}
	else if (array->xpos < x)
	{
		*span =*span/7;
		b = moveRight(array, x);
	}

	if (b)
	{
		float m = (move.y - array->size.y - (move.y * 2 - array->size.y)) / (x - array->xpos);
		float c = (move.y - array->size.y) - m * x;
		array->pos.y = m * array->pos.x + c;
	}

	if (array->xpos == x)
	{
		*span = *span / 2;
		b = moveUp(array);
	}
	
	if(!b)
	{
		array->pos.y = move.y - array->size.y;
		array->xpos = array->pos.x;
		temp_merge_array[index] = *array;
		temp_merge_array[index].pos.y = ofGetHeight() - array->size.y;
	}

	return  b;
}
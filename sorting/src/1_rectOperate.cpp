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
		*span = *span / 5;//Couldn't find a way to reduce speed of diagonal movement so reduced span
		cout << array->xpos << "    " << x << endl;
		cout << "Called1";
		b = moveLeft(array, x);
		array->pos.y = -((move.y / (x - array->xpos)) * array->pos.x) + (ofGetHeight() - array->size.y + ((move.y) / (x - array->xpos)) * array->xpos);//y=mx formso that moves in diagonal
	}
	else if (array->xpos < x)
	{
		*span = *span / 5;//Couldn't find a way to reduce speed of diagonal movement so reduced span
		cout << "called2";
		b = moveRight(array, x);
		array->pos.y = -((move.y / (x - array->xpos)) * array->pos.x) + (ofGetHeight() - array->size.y + ((move.y) / (x - array->xpos)) * array->xpos);//y=mx formso that moves in diagonal
	}
	else if (array->xpos == x)
	{
		b = moveUp(array);
	}
	if (!b)
	{
		array->pos.y = move.y - array->size.y;
		array->xpos = array->pos.x;
		temp_merge_array[index] = *array;
		temp_merge_array[index].pos.y = ofGetHeight() - array->size.y;
	}
	return  b;
}
#pragma once
#include"dat.h"

class rectOperate
{
private:
	bool a, b, c;
	float *span,width,height;
public:
	rectOperate(float* _span,float _width,float _height)
	{
		width = _width;
		a = 1;
		b = c=0;
		span = _span;
		height = _height;
	};
	//These are in 1_rectOperate.cpp
	//==================================
		bool moveRight(dat * array, float point_x);
		bool moveLeft(dat * array, float point_x);
		bool moveUp(dat * array);
		bool moveDown(dat * array);
		bool moveTo(dat* array,int x,dat *temp_merge_array);
	//=======================================================


	//These are in 2_rectOperate.cpp;
	//========================================================
		bool rectOperationSwap(dat* array1, dat* array2);
		bool rectOperationShift(dat* array1, dat* array2);
		bool moveUp(dat* array1, dat* array2);
		bool moveDown(dat* array1, dat* array2);
		bool rectSwap(dat* array1, dat* array2);
	//=====================================================
		float ofGetHeight()
		{
			return height;
		}
};
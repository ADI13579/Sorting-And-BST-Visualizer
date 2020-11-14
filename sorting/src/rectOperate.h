#pragma once
#include"ofMain.h"
#include"dat.h"
class rectOperate
{
private:
	int *span;
	ofVec2f move;
	ofVec2f scale;
	int number;
public:
	rectOperate(int* _span, ofVec2f screen_size_half,ofVec2f scale_of_bars,int num)
	{
		span = _span;
		move = screen_size_half;
		scale = scale_of_bars;
		number = num;
	};
	//These are in 1_rectOperate.cpp
	//==================================
		bool moveRight(dat * array, float point_x);
		bool moveLeft(dat * array, float point_x);
		bool moveUp(dat * array);
		bool moveDown(dat * array);
		bool moveTo(dat* array,int x);

	//=======================================================


	//These are in 2_rectOperate.cpp;
	//========================================================
		bool rectOperationSwap(dat* array1, dat* array2);
		bool rectOperationShift(dat* array1, dat* array2);
		bool moveUp(dat* array1, dat* array2);
		bool moveDown(dat* array1, dat* array2);
		bool rectSwap(dat* array1, dat* array2);
	//=====================================================

		bool a=1, b=0, c=0;
};
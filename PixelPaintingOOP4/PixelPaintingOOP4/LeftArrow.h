#pragma once
#include "GeometricObject.h"
void drawLeftArrow(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue);

class LeftArrow : public GeometricObject
{
public:
	int start_x, start_y;
	int middle_x, middle_y;
	int a, b;
	int end_x, end_y;
public:
	LeftArrow(const int& _start_x, const int& _start_y, const int& _middle_x, const int& _middle_y, const int& _a, const int& _b, const int& _end_x, const int& _end_y)
	{
		initialize(_start_x, _start_y, _middle_x, _middle_y, _a, _b, _end_x, _end_y);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _middle_x, const int& _middle_y, const int& _a, const int& _b, const int& _end_x, const int& _end_y);

	void draw();
};
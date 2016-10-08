#pragma once
#include "GeometricObject.h"
void drawSmallCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue);

class smallCircle : public GeometricObject
{
public:
	int start_x, start_y;
	int r;

	smallCircle(const int& _start_x, const int& _start_y, const int& _r)
	{
		initialize(_start_x, _start_y, _r);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _r);
	

	void draw();
};
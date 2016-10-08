#pragma once
#include "GeometricObject.h"
void drawAicon(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int&j2, const float& red, const float& green, const float& blue);

class Aicon : public GeometricObject
{
public:
	int i0, j0;
	int i1, j1;
	int i2, j2;
public:
	Aicon(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2)
	{
		initialize(_i0, _j0, _i1, _j1, _i2, _j2);
	}
	void initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2);

	void draw();
};
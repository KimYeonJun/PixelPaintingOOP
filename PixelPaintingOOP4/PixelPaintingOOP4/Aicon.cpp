#include "Aicon.h"
void Aicon::initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2)
{
	i0 = _i0;
	j0 = _j0;
	i1 = _i1;
	j1 = _j1;
	i2 = _i2;
	j2 = _j2;
}

void Aicon::draw()
{
	drawAicon(i0, j0, i1, j1, i2, j2, 0.0f, 0.0f, 1.0f);
}
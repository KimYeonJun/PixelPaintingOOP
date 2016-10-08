#include "DownArrow.h"
void DownArrow::initialize(const int& _start_x, const int& _start_y, const int& _middle_x, const int& _middle_y, const int& _a, const int& _b, const int& _end_x, const int& _end_y)
{
	start_x = _start_x;
	start_y = _start_y;
	middle_x = _middle_x;
	middle_y = _middle_y;
	a = _a;
	b = _b;
	end_x = _end_x;
	end_y = _end_y;
}

void DownArrow::draw()
{
	drawDownArrow(start_x, start_y, middle_x, middle_y, a, b, end_x, end_y, 0.0f, 0.0f, 1.0f);
}
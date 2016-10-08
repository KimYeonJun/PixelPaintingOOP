#include "SmallCircle.h"

void smallCircle :: initialize(const int& _start_x, const int& _start_y, const int& _r)
{
	start_x = _start_x;
	start_y = _start_y;
	r = _r;
}
void smallCircle::draw()
{
	drawSmallCircle(start_x, start_y, r, 0.0f, 0.0f, 1.0f);

}
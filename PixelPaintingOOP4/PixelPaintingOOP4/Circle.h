#pragma once
#include "GeometricObject.h"
//#include <GLFW/glfw3.h>
//GLFWwindow* window;
void drawCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue);
//void drawIcon(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue, GLFWwindow* window);


class Circle : public GeometricObject
{
public:
	int start_x, start_y;
	int r;

	Circle(const int& _start_x, const int& _start_y, const int& _r)
	{
		initialize(_start_x, _start_y, _r);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _r);

	void draw();
};
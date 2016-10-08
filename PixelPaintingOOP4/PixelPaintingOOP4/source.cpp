#include <GLFW/glfw3.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <time.h>
#include <iostream>
#include "math.h"
#include "ThickLine.h"
#include "GeometricObject.h"
#include "SmallCircle.h"
#include "Square.h"
#include "Xicon.h"
#include "DownArrow.h"
#include "RightArrow.h"
#include "Aicon.h"
#include "LeftArrow.h"
#include "UpArrow.h"
#include "Circle.h"
#include "SquareIcon.h"
const int width = 1300;
const int height = 1200;
GLFWwindow* window;
float* pixels = new float[width*height * 3];
GeometricObject **my_objects = new GeometricObject*[40];
void drawIcon(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue, GLFWwindow* window);
void drawSquareIcon2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue, GLFWwindow *window);

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 == i1)
	{
		for (int j = j0;j < j1;j++)
		{
			drawPixel(i0, j, red, green, blue);
		}
		return;
	}
	for (int i = i0; i <= i1; i++)
	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawThickLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 == i1)
	{
		for (int j = j0;j < j1;j++)
		{
			drawPixel(i0, j, red, green, blue);
		}
		return;
	}
	for (int i = i0; i <= i1; i++)
	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j - 1, red, green, blue);
		drawPixel(i, j, red, green, blue);
		drawPixel(i, j + 1, red, green, blue);
	}
	
}
void drawAicon(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int&j2, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i2, j2, red, green, blue);
	drawLine(i2, j2, i1, j1, red, green, blue);
	drawLine((i0 + i2) / 2, (j0 + j2) / 2, (i2 + i1) / 2, (j2 + j1) / 2, red, green, blue);
}
void drawXicon(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i0, j1, i1, j0, red, green, blue);
}
void drawUpArrow(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i1, j1, i2, j2, red, green, blue);
	drawLine(i3, j3, i1, j1, red, green, blue);
}
void drawLeftArrow(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue)
{
	drawLine(i1, j1, i0, j0, red, green, blue);
	drawLine(i1, j1, i2, j2, red, green, blue);
	drawLine(i1, j1, i3, j3, red, green, blue);

}
void drawRightArrow(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i2, j2, i1, j1, red, green, blue);
	drawLine(i3, j3, i1, j1, red, green, blue);

}
void drawDownArrow(const int& i0, const int& j0, const int& i1, const int& j1, const int& i2, const int& j2, const int& i3, const int& j3, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i1, j1, i2, j2, red, green, blue);
	drawLine(i1, j1, i3, j3, red, green, blue);

}

void drawSquare(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j0, red, green, blue);
	drawLine(i1, j0, i1, j1, red, green, blue);
	drawLine(i0, j1, i1, j1, red, green, blue);
	drawLine(i0, j0, i0, j1, red, green, blue);

}
void drawSquareIcon(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i1, j0, red, green, blue);
	drawLine(i1, j0, i1, j1, red, green, blue);
	drawLine(i0, j1, i1, j1, red, green, blue);
	drawLine(i0, j0, i0, j1, red, green, blue);
	
	drawSquareIcon2(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f,window);
}
void drawSquareIcon2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue, GLFWwindow *window)
{

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	ypos = height - ypos - 1;
	/*if (xpos <= i0 + edge && xpos >= i0 && ypos <= j0 + edge && ypos >= j0) {
		drawLine(i0, j0, i0 + edge, j0, 1.0f, 0.0f, 0.0f);
		drawLine(i0 + edge, j0, i0 + edge, j0 + edge, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0 + edge, i0 + edge, j0 + edge, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0, i0, j0 + edge, 1.0f, 0.0f, 0.0f);
	}
	else {
		drawLine(i0, j0, i0 + edge, j0, 0.0f, 0.0f, 1.0f);
		drawLine(i0 + edge, j0, i0 + edge, j0 + edge, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0 + edge, i0 + edge, j0 + edge, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0, i0, j0 + edge, 0.0f, 0.0f, 1.0f);

	}*/
	if (xpos >= i0&&xpos <= i1&&ypos >= j0&&ypos <= j1)
	{
		drawLine(i0, j0, i1, j0, red, green, blue);
		drawLine(i1, j0, i1, j1, red, green, blue);
		drawLine(i0, j1, i1, j1, red, green, blue);
		drawLine(i0, j0, i0, j1, red, green, blue);
	}



}
//void drawCircle(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
void drawCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue)
{

	for (int i = i0 - r;i <= i0 + r;i++)
	{
		for (int j = j0 - r;j <= j0 + r;j++)
		{
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;

			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 3)*(r - 3);
			if (f <= 0 && f1 >= 0)
			{

				drawPixel(i, j, red, blue, green);

			}

		}
	}

	drawIcon(i0, j0, r, 0.0f, 0.0f,1.0f, window);

}
void drawIcon(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue, GLFWwindow* window)
{
	double xpos, ypos;
	
	for (int i = i0 - r;i <= i0 + r;i++)
	{
		for (int j = j0 - r;j <= j0 + r;j++)
		{
			glfwGetCursorPos(window, &xpos, &ypos);
			ypos = height - ypos - 1;
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;
			int f2 = (xpos - i0)*(xpos - i0) + (ypos - j0)*(ypos - j0) - r*r;
			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 3)*(r - 3);
			if (f2 <= 0)
			{
				if (f <= 0 && f1 >= 0)
				{
					drawPixel(i, j, red, green, blue);
				}
			}


		}
	}


}
void drawSmallCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue)
{

	for (int i = i0 - r;i <= i0 + r;i++)
	{
		for (int j = j0 - r;j <= j0 + r;j++)
		{
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;

			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 10)*(r - 10);
			if (f <= 0 && f1 >= 0)
			{

				drawPixel(i, j, red, blue, green);

			}

		}
	}
	

}
void drawOnPixelBuffer(GLFWwindow* window)
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	/*drawPixel(i, j, 0.0f, 0.0f, 0.0f);*/

	// drawing a line
	//TODO: anti-aliasing
	for (int i = 0;i < 40;i++)
	{
		my_objects[i]->draw();
	}
	/*for (int i = 0;i < 10;i++)
	{
		my_objects2[i]->draw();
	}*/
}

int main(void)
{
	int count = 0;


	for (int i = 0;i < 40;i++)
	{
		if (i == 0)
		{
			my_objects[i] = new ThickLine(80, 300, 150, 400);
		}
		else if (i == 1)
		{
			my_objects[i] = new smallCircle(360, 360, 30);
		}
		else if (i == 2)
		{
			my_objects[i] = new Square(575, 335, 625, 385);
		}
		else if (i == 3)
		{
			my_objects[i] = new Xicon(790, 300, 890, 420);
		}
		else if (i == 4)
		{
			my_objects[i] = new DownArrow(1050, 320, 1080, 300, 1110, 320, 1080, 400);
		}
		else if (i == 5)
		{
			my_objects[i] = new RightArrow(150, 160, 180, 120, 150, 80, 60, 120);
		}

		else if (i == 6)
		{
			my_objects[i] = new Aicon(290, 80, 430, 80, 360, 180);
		}

		else if (i == 7)
		{
			my_objects[i] = new ThickLine(600, 50, 600, 180);
		}
		else if (i == 8)
		{
			my_objects[i] = new LeftArrow(810, 160, 780, 120, 810, 80, 880, 120);
		}
		else if (i == 9)
		{
			my_objects[i] = new UpArrow(1050, 150, 1080, 180, 1110, 150, 1080, 50);
		}
		else if (i == 10)
		{
			my_objects[i] = new ThickLine(80, 780, 150, 880);
		}
		else if (i == 11)
		{
			my_objects[i] = new smallCircle(360, 840, 30);
		}
		else if (i == 12)
		{
			my_objects[i] = new Square(575, 815, 625, 865);
		}
		else if (i == 13)
		{
			my_objects[i] = new Xicon(790, 780, 890, 900);
		}
		else if (i == 14)
		{
			my_objects[i] = new DownArrow(1050, 800, 1080, 780, 1110, 800, 1080, 880);
		}
		else if (i == 15)
		{
			my_objects[i] = new RightArrow(150, 640, 180, 600, 150, 560, 60, 600);
		}

		else if (i == 16)
		{
			my_objects[i] = new Aicon(290, 560, 430, 560, 360, 660);
		}

		else if (i == 17)
		{
			my_objects[i] = new ThickLine(600, 530, 600, 660);
		}
		else if (i == 18)
		{
			my_objects[i] = new LeftArrow(810, 640, 780, 600, 810, 560, 880, 600);
		}
		else if (i == 19)
		{
			my_objects[i] = new UpArrow(1050, 630, 1080, 660, 1110, 630, 1080, 530);
		}
		/*else if (i >= 20 && i < 25)
		{
			my_objects[i] = new Circle(120 + 240 * (i - 20), 120, 100);
		}
		else if (i >= 25 && i < 30)
		{
			my_objects[i] = new Circle(120 + 240 * (i - 25), 360, 100);
		}
		else if (i >= 30 && i < 35)
		{
			my_objects[i] = new Circle(120 + 240 * (i - 30), 600, 100);
		}
		else if (i >= 35 && i < 40)
		{
			my_objects[i] = new Circle(120 + 240 * (i - 35), 840, 100);
		}*/
		else if (i >= 20 && i < 25)
		{
			my_objects[i] = new SquareIcon(20 + 240 * (i - 20), 20, 220 + 240 * (i - 20), 220);
		}
		else if (i >= 25 && i < 30)
		{
			my_objects[i] = new SquareIcon(20 + 240 * (i - 25), 260, 220 + 240 * (i - 25), 460);
		}
		else if (i >= 30 && i < 35)
		{
			my_objects[i] = new SquareIcon(20 + 240 * (i - 30), 500, 220 + 240 * (i - 30), 700);
		}
		else if (i >= 35 && i < 40)
		{
			my_objects[i] = new SquareIcon(20 + 240 * (i - 35), 740, 220 + 240 * (i - 35), 940);
		}
	}
	
	

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(window);

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}


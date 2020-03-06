#pragma once
#include<GLFW/glfw3.h>
#include<iostream>
#include <stdlib.h>
#include <math.h>

class Helper
{
public:
	Helper();
	~Helper();
	void setup(GLFWwindow* window, int width, int height);
	void drawPixel(int x, int y);
	void drawPoint(GLint pointVertex[], int size);
	void drawQuad(float vertices[]);
	void drawBresenhamsLine(int x0, int y0, int xEnd, int yEnd, int displayWidth, int displayHeight);
	
	void moveQuadToRight(float vertices[]);
	void moveQuadToLeft(float vertices[]);
	void scaleQuadUpper(float vertices[]);
	void scaleQuadDown(float vertices[]);
private:
};

// glColor3f(1.0, 0.0, 0.0);
#include "Helper.h"

Helper::Helper()
{
}

Helper::~Helper()
{
}

void Helper::setup(int displayWidth, int displayHeight) {
	/*
	* Specifies the part of the window to which OpenGL will
	* draw (in pixels), convert from normalised to pixels.
	*/
	glViewport(0, 0, displayWidth, displayHeight);
	/*
	* Defines the property of the camera that views the objects
	* in the world coordinate frame. Here you typically set the
	* zoom factor, aspec ratio and the near and far clipping planes.
	*/
	glMatrixMode(GL_PROJECTION);
	/*
	* Replace the current matrix with the identity matrix and
	* start us a fresh because matrix transforms such as
	* glOrtho and glRotated cumulate, basically put us at (0, 0, 0).
	*/
	glLoadIdentity();
	// Set Coordinates System.
	glOrtho(0, displayWidth, 0, displayHeight, 0, 1);
	/*
	* Modelview matrix defines how your objects are transformed
	* in your world.
	*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Helper::drawPoint(GLint pointVertex[]) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glPointSize(1);
	glVertexPointer(2, GL_INT, 0, pointVertex);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Helper::drawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void Helper::drawQuad(float vertices[]) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/* Bresenham line-drawing procedure for |m| < 1.0. */
void Helper::drawBresenhamsLine(int x0, int y0, int xEnd, int yEnd, int displayWidth, int displayHeight) {
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	/* Determine which endpoint to use as start position. */
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}

	else {
		x = x0;
		y = y0;
	}

	drawPixel(x, y);

	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}

		if (x > (displayWidth / 3) && x < (displayWidth / 3 * 2)
			&& y >(displayHeight / 3) && y < (displayHeight / 3 * 2))
			glColor3f(0.0, 0.0, 1.0);

		drawPixel(x, y);
		glColor3f(1.0, 1.0, 1.0);
	}
	glFlush();
}
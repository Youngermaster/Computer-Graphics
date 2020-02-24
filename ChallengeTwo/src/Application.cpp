#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include "Helper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define LOG(x) std::cout << x << std::endl

int main(void) {
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Challenge Two", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the windows's context current */
	glfwMakeContextCurrent(window);

	glewInit();

	LOG(glGetString(GL_VERSION));
	LOG(Helper().getTest());

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events*/
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
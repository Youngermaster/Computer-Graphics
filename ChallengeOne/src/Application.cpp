#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

#include "Helper.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Challenge One", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the windows's context current */
	glfwMakeContextCurrent(window);

	Helper().setup(SCREEN_WIDTH, SCREEN_HEIGHT);

	glewInit();

	std::cout << glGetString(GL_VERSION) << std::endl;

	float vertices[]
	{
		SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 * 2, 0.0,
		SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3 * 2, 0.0,
		SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3, 0.0,
		SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, 0.0
	};

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		Helper().drawQuad(vertices);
		Helper().drawBresenhamsLine(50, 50, 170, 90, SCREEN_WIDTH, SCREEN_HEIGHT);
		Helper().drawBresenhamsLine(350, 250, 180, 96, SCREEN_WIDTH, SCREEN_HEIGHT);
		Helper().drawBresenhamsLine(150, 220, 600, 450, SCREEN_WIDTH, SCREEN_HEIGHT);
		Helper().drawBresenhamsLine(250, 270, 400, 450, SCREEN_WIDTH, SCREEN_HEIGHT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events*/
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
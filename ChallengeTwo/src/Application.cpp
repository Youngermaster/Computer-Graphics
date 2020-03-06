#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include <math.h>

#include "Helper.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define LOG(x) std::cout << x << std::endl

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
float vertices[]
{
    SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 * 2, 0.0,
    SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3 * 2, 0.0,
    SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 3, 0.0,
    SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, 0.0
};
int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Challenge Two", NULL, NULL);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    Helper helper = Helper();

    helper.setup(window, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        helper.drawQuad(vertices);
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    LOG(key);

    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT)
    {
        LOG("Space Key Pressed");
    }
    if (key == GLFW_KEY_RIGHT)
    {
        Helper().moveQuadToRight(vertices);
        LOG("Move to right");
    }
    if (key == GLFW_KEY_LEFT)
    {
        Helper().moveQuadToLeft(vertices);
        LOG("Move to left");
    }
    if (key == GLFW_KEY_UP)
    {
        Helper().scaleQuadUpper(vertices);
        LOG("Scale Upper");
    }
    if (key == GLFW_KEY_DOWN)
    {
        Helper().scaleQuadDown(vertices);
        LOG("Scale Down");
    }
}

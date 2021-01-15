#include "GLFWWindow.h"
#include <iostream>

GLFWWindow::GLFWWindow(int width, int height, std::string name, int openGLMajorVersion, int openGLMinorVersion)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLMajorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLMinorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glViewport(0, 0, width, height);
}

bool GLFWWindow::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void GLFWWindow::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void GLFWWindow::ProcessInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void GLFWWindow::PollEvents()
{
    glfwPollEvents();
}

void GLFWWindow::Terminate()
{
    glfwTerminate();
}
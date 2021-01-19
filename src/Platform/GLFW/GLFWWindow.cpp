#include "GLFWWindow.h"
#include <iostream>

void GLAPIENTRY
MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
}

GLFWWindow::GLFWWindow(int width, int height, std::string name, int openGLMajorVersion, int openGLMinorVersion)
{
    glfwInit();


    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLMajorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLMinorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glViewport(0, 0, width, height);
}

bool GLFWWindow::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

void GLFWWindow::SwapBuffers()
{
    glfwSwapBuffers(m_Window);
}

void GLFWWindow::ProcessInput()
{
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}

void GLFWWindow::PollEvents()
{
    glfwPollEvents();
}

void GLFWWindow::Terminate()
{
    glfwTerminate();
}
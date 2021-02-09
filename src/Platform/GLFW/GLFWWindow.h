#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Platform/Abstract/AbstractWindow.h"

class GLFWWindow : public AbstractWindow
{
public:
	GLFWWindow(int width, int height, std::string name, int openGLMajorVersion, int openGLMinorVersion);
	void ProcessInput();
	bool ShouldClose();
	void SwapBuffers();
	void PollEvents();
	void Terminate();
private:
	GLFWwindow* m_Window = nullptr;
};
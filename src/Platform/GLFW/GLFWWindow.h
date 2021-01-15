#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Abstract/AbstractWindow.h"

class GLFWWindow : public AbstractWindow
{
public:
	GLFWWindow(int width, int height, std::string name, int openGLMajorVersion = 4, int openGLMinorVersion = 6);
	void ProcessInput();
	bool ShouldClose();
	void SwapBuffers();
	void PollEvents();
	void Terminate();
private:
	GLFWwindow* window = nullptr;
};
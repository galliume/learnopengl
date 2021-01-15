#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, std::string name, int openGLMajorVersion = 4, int openGLMinorVersion = 6);
	void ProcessInput();
	bool ShouldClose();
	void SwapBuffers();
	GLFWwindow* GetWindow() { return window; };
private:
	GLFWwindow* window = nullptr;
};
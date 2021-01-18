#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
	static void Clear();
	static void DrawArrays(unsigned int VAO, GLsizei count, GLenum mode = GL_TRIANGLES);
	static void DrawElements(unsigned int VAO, GLsizei count, GLenum mode = GL_TRIANGLES);
};
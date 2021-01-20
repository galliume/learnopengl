#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
	VertexBuffer(const void* data, int size, GLsizei n = 1, GLenum type = GL_STATIC_DRAW);
	unsigned int GetId() { return m_VBO; };
	void Delete();
private:
	unsigned int m_VBO = 0;
	GLenum m_Target = GL_ARRAY_BUFFER;
	GLenum m_Type = GL_STATIC_DRAW;
};
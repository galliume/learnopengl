#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
	VertexBuffer(const void* data, int size, GLsizei n = 1, GLenum type = GL_STATIC_DRAW);
	void SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE);
	void UnBind();
	void Delete();
private:
	unsigned int m_VBO = 0;
	GLenum m_Target = GL_ARRAY_BUFFER;
	GLenum m_Type = GL_STATIC_DRAW;
};
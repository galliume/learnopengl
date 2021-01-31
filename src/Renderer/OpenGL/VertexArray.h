#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IndexVertexBuffer.h"

class VertexArray
{
public:
	VertexArray(GLsizei n, IndexVertexBuffer vertexBuffer);
	unsigned int GetVAO() { return m_VAO; };
	void SetAttribPointer(GLint count, GLsizei stride, GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE);
	void Bind();
	void Delete();
private:
	GLuint m_VAO = 0;
	IndexVertexBuffer m_VBO;
};
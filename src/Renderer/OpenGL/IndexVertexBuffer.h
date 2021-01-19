#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class IndexVertexBuffer
{
public:
	IndexVertexBuffer(const void* vertices, int verticesSize, const void* indices, int indicesSize, GLenum type = GL_STATIC_DRAW);
	void SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE);
	void Delete();
private:
	unsigned int m_EBO = 0;
	unsigned int m_VBO = 0;
	GLenum m_Target = GL_ELEMENT_ARRAY_BUFFER;
};
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
	unsigned int EBO = 0;
	unsigned int VBO = 0;
	GLenum target = GL_ELEMENT_ARRAY_BUFFER;
};
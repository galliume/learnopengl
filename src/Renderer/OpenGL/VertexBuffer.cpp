#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int size, GLsizei n, GLenum type) : type(type)
{
	glGenVertexArrays(n, &VAO);
	glGenBuffers(n, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(target, VBO);
	glBufferData(target, size, data, type);
}

void VertexBuffer::SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type, GLboolean normalized)
{
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
	glEnableVertexAttribArray(0);
	glBindBuffer(target, 0);
}

void VertexBuffer::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
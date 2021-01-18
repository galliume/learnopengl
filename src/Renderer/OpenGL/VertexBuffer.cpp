#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int size, GLsizei n, GLenum type) : type(type)
{
	glGenBuffers(n, &VBO);
	glBufferData(target, size, data, type);
}

void VertexBuffer::Bind()
{
	glBindBuffer(target, VBO);
}

void VertexBuffer::UnBind()
{
	glBindBuffer(target, 0);
}

void VertexBuffer::SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type, GLboolean normalized)
{
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
	glEnableVertexAttribArray(0);
}

void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &VBO);
}
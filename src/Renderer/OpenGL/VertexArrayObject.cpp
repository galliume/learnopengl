#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject(GLsizei n, GLenum target, const void* data, GLenum usage)
{
	glGenVertexArrays(n, &VAO);
	glGenBuffers(n, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(target, VBO);
	glBufferData(target, sizeof(data), data, usage);
}

void VertexArrayObject::SetAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride * sizeof(float), (void*)pointer);
	glEnableVertexAttribArray(index);
	glBindBuffer(target, index);
	glBindVertexArray(0);
}

void VertexArrayObject::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLenum target, const void* data, GLenum usage)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(target, VBO);
	glBufferData(target, sizeof(data), data, usage);
}

void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &VBO);
}
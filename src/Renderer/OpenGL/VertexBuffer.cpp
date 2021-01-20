#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int size, GLsizei n, GLenum type) : m_Type(type)
{
	glGenBuffers(n, &m_VBO);
	glBindBuffer(m_Target, m_VBO);
	glBufferData(m_Target, size, data, m_Type);
}

void VertexBuffer::UnBind()
{
	glBindBuffer(m_Target, 0);
}

void VertexBuffer::SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type, GLboolean normalized)
{
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
}

void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &m_VBO);
}
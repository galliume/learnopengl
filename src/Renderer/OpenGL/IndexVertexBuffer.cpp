#include "IndexVertexBuffer.h"

IndexVertexBuffer::IndexVertexBuffer(const void* vertices, int verticesSize, const void* indices, int indicesSize, GLenum type)
{
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, type);

	glBindBuffer(m_Target, m_EBO);
	glBufferData(m_Target, indicesSize, indices, type);
}

void IndexVertexBuffer::SetAttribPointer(GLint size, GLsizei stride, const void* pointer, GLenum type, GLboolean normalized)
{
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
	glEnableVertexAttribArray(0);
}

void IndexVertexBuffer::Delete()
{
	glDeleteBuffers(1, &m_EBO);
	glDeleteBuffers(1, &m_VBO);
}
#include "VertexArray.h"

VertexArray::VertexArray(GLsizei n)
{
	glGenVertexArrays(n, &m_VAO);
	glBindVertexArray(m_VAO);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &m_VAO);
}

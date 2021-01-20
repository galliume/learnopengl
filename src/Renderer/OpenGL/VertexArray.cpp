#include "VertexArray.h"

VertexArray::VertexArray(GLsizei n)
{
	glGenVertexArrays(n, &m_VAO);
}
void VertexArray::Bind()
{
	glBindVertexArray(m_VAO);
	glEnableVertexAttribArray(0);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &m_VAO);
}
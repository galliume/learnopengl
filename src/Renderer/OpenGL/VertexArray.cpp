#include "VertexArray.h"

VertexArray::VertexArray(GLsizei n)
{
	glGenVertexArrays(n, &VAO);
	glBindVertexArray(VAO);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &VAO);
}

#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
}
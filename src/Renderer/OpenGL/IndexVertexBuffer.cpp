#include "IndexVertexBuffer.h"

IndexVertexBuffer::IndexVertexBuffer(const void* vertices, int verticesSize, const void* indices, int indicesSize, GLenum type)
{
	/* opengl 3 
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, type);

	glBindBuffer(m_Target, m_EBO);
	glBufferData(m_Target, indicesSize, indices, type);
	*/

	/* opengl 4 */
	glCreateBuffers(1, &m_VBO);
	glNamedBufferData(m_VBO, verticesSize, vertices, GL_STATIC_DRAW);

	glCreateBuffers(1, &m_EBO);
	glNamedBufferData(m_EBO, indicesSize, indices, GL_STATIC_DRAW);
}

void IndexVertexBuffer::Delete()
{
	glDeleteBuffers(1, &m_EBO);
	glDeleteBuffers(1, &m_VBO);
}
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int size, GLsizei n, GLenum type) : m_Type(type)
{
	/* opengl 3 
	glGenBuffers(n, &m_VBO);
	glBindBuffer(m_Target, m_VBO);
	glBufferData(m_Target, size, data, m_Type);
	*/

	/* opengl 4 */
	glCreateBuffers(n, &m_VBO);
	glNamedBufferData(m_VBO, size, data, m_Type);
	glBindBuffer(m_Type, m_VBO);
}

void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &m_VBO);
}
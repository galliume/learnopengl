#include "VertexArray.h"

VertexArray::VertexArray(GLsizei n, IndexVertexBuffer vertexBuffer) : m_VBO(vertexBuffer)
{
	/* opengl 3 
	glGenVertexArrays(n, &m_VAO);
	*/

	/* opengl 4 */
	glCreateVertexArrays(n, &m_VAO);
}

void VertexArray::SetAttrib(GLenum type, GLboolean normalized)
{
	/* opengl 3
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
	glEnableVertexAttribArray(0);
	*/

	/* opengl 4*/
	glEnableVertexArrayAttrib(m_VAO, 0);
	glVertexArrayAttribFormat(m_VAO, 0, 3, type, normalized, 0);
	glVertexArrayAttribBinding(m_VAO, 0, 0);

	glEnableVertexArrayAttrib(m_VAO, 1);
	glVertexArrayAttribFormat(m_VAO, 1, 3, type, normalized, 12);
	glVertexArrayAttribBinding(m_VAO, 1, 0);

	glEnableVertexArrayAttrib(m_VAO, 2);
	glVertexArrayAttribFormat(m_VAO, 2, 2, type, normalized, 24);
	glVertexArrayAttribBinding(m_VAO, 2, 0);

	glVertexArrayVertexBuffer(m_VAO, 0, m_VBO.GetVBOID(), 0, 32);
	glVertexArrayElementBuffer(m_VAO, m_VBO.GetEBOID());
}

void VertexArray::BindTexture(unsigned int texture)
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

void VertexArray::Bind()
{
	glBindVertexArray(m_VAO);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &m_VAO);
}
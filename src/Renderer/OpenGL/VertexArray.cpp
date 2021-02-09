#include "VertexArray.h"

VertexArray::VertexArray(GLsizei n, IndexVertexBuffer vertexBuffer) : m_VBO(vertexBuffer)
{
	/* opengl 3 
	glGenVertexArrays(n, &m_VAO);
	*/

	/* opengl 4 */
	glCreateVertexArrays(n, &m_VAO);
}

void VertexArray::SetAttribPointer(GLint count, GLsizei stride, GLenum type, GLboolean normalized)
{
	/* opengl 3
	glVertexAttribPointer(0, size, type, normalized, stride * sizeof(float), pointer);
	glEnableVertexAttribArray(0);
	*/

	/* opengl 4*/
	glEnableVertexArrayAttrib(m_VAO, 0);
	glVertexArrayAttribFormat(m_VAO, 0, count, type, normalized, 0);
	glVertexArrayAttribBinding(m_VAO, 0, 0);

	glEnableVertexArrayAttrib(m_VAO, 1);
	glVertexArrayAttribFormat(m_VAO, 1, count, type, normalized, count * sizeof(float));
	glVertexArrayAttribBinding(m_VAO, 1, 0);

	glVertexArrayVertexBuffer(m_VAO, 0, m_VBO.GetVBOID(), 0, stride * sizeof(float));
	glVertexArrayElementBuffer(m_VAO, m_VBO.GetEBOID());
}

void VertexArray::Bind()
{
	glBindVertexArray(m_VAO);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &m_VAO);
}
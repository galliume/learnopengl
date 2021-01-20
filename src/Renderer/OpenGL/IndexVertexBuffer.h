#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class IndexVertexBuffer
{
public:
	IndexVertexBuffer(const void* vertices, int verticesSize, const void* indices, int indicesSize, GLenum type = GL_STATIC_DRAW);
	unsigned int GetVBOID() { return m_VBO; };
	unsigned int GetEBOID() { return m_EBO; };
	void Delete();
private:
	unsigned int m_EBO = 0;
	unsigned int m_VBO = 0;
	GLenum m_Target = GL_ELEMENT_ARRAY_BUFFER;
	GLenum m_Type = GL_STATIC_DRAW;
};
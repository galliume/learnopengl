#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexArray
{
public:
	VertexArray(GLsizei n = 1);
	unsigned int GetVAO() { return m_VAO; };
	void Bind();
	void Delete();
private:
	unsigned int m_VAO = 0;
};
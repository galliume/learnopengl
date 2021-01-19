#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	void AddVertex(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void AddFragment(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void Bind();
	void Delete();
private:
	unsigned int m_VertexShader;
	unsigned int m_FragmentShader;
	unsigned int m_ShaderProgram;
private:
	unsigned int AddShader(GLenum shaderType, GLsizei count, const GLchar** string, const GLint* length = NULL);
};
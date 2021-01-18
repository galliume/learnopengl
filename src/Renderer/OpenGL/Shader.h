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
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
private:
	unsigned int AddShader(GLenum shaderType, GLsizei count, const GLchar** string, const GLint* length = NULL);
};
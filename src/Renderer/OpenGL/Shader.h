#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	void AddVertexShader(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void AddFragmentShader(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void Link();
	void Draw(unsigned int VAO, GLenum mode, GLint first, GLsizei count);
	void Delete();
private:
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
private:
	unsigned int AddShader(GLenum shaderType, GLsizei count, const GLchar** string, const GLint* length = NULL);
};
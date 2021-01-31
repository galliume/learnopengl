#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void AddVertex(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void AddFragment(GLsizei count, const GLchar** string, const GLint* length = NULL);
	void Bind();
	void Delete();
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void CheckCompileErrors(unsigned int shader, std::string type);
private:
	unsigned int m_VertexShader;
	unsigned int m_FragmentShader;
	unsigned int m_ShaderProgram;
private:
	unsigned int AddShader(GLenum shaderType, GLsizei count, const GLchar** string, const GLint* length = NULL);
};
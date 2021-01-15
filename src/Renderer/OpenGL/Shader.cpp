#include "Shader.h"

void Shader::AddVertexShader(GLsizei count, const GLchar** string, const GLint* length)
{
	vertexShader = AddShader(GL_VERTEX_SHADER, count, string, length);
}
void Shader::AddFragmentShader(GLsizei count, const GLchar** string, const GLint* length)
{	
	fragmentShader = AddShader(GL_FRAGMENT_SHADER, count, string, length);
}

void Shader::Link()
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		exit(-1);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Draw(unsigned int VAO, GLenum mode, GLint first, GLsizei count)
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(mode, first, count);
}

void Shader::Delete()
{
	glDeleteProgram(shaderProgram);
}

unsigned int Shader::AddShader(GLenum shaderType, GLsizei count, const GLchar** string, const GLint* length)
{
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, count, string, length);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		exit(-1);
	}

	return shader;
}
#include "Shader.h"

void Shader::AddVertex(GLsizei count, const GLchar** string, const GLint* length)
{
	m_VertexShader = AddShader(GL_VERTEX_SHADER, count, string, length);
}
void Shader::AddFragment(GLsizei count, const GLchar** string, const GLint* length)
{	
	m_FragmentShader = AddShader(GL_FRAGMENT_SHADER, count, string, length);
}

void Shader::Bind()
{
	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, m_VertexShader);
	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glLinkProgram(m_ShaderProgram);

	int  success;
	char infoLog[512];
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		exit(-1);
	}

	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);


	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(m_ShaderProgram, "u_Time");

	glUseProgram(m_ShaderProgram);
	glUniform1f(vertexColorLocation, greenValue);
}

void Shader::Delete()
{
	glDeleteProgram(m_ShaderProgram);
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
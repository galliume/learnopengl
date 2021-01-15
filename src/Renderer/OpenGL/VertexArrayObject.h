#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexArrayObject
{
public:
	VertexArrayObject(GLsizei n, GLenum target, const void* data, GLenum usage);
	void SetAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	unsigned int GetVAO() { return VAO; };
	unsigned int GetVBO() { return VBO; };
	void Delete();
private:
	unsigned int VAO;
	unsigned int VBO;
	GLenum target = 0;
};
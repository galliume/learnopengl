#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexArray
{
public:
	VertexArray(GLsizei n = 1);
	unsigned int GetVAO() { return VAO; };
	void Delete();
private:
	unsigned int VAO = 0;
};
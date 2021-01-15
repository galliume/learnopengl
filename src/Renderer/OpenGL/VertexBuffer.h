#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
	VertexBuffer(GLenum target, const void* data, GLenum usage);
	unsigned int GetVBO() { return VBO; };
	void Delete();
private:
	unsigned int VBO;
};
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Abstract/AbstractRenderer.h"

class OpenGLRenderer : public AbstractRenderer
{
public:
	OpenGLRenderer(bool drawAsPolygon = false);
	void Clear();
	void Draw(int count);
private:
	GLenum m_Mode = GL_TRIANGLES;
};
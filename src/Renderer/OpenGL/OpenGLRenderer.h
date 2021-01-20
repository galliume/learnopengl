#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Abstract/AbstractRenderer.h"

class OpenGLRenderer : public AbstractRenderer
{
public:
	OpenGLRenderer(bool drawAsPolygon = false, bool debugMode = true);
	void Clear();
	void Draw(int count);
private:
	GLenum m_Mode = GL_TRIANGLES;
};
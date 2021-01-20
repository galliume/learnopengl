#include "Renderer.h"

Renderer::Renderer(bool drawAsPolygon)
{
	if (drawAsPolygon)	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Renderer::Clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawArrays(GLsizei count, GLenum mode)
{
	glDrawArrays(mode, 0, count);
}

void Renderer::DrawElements(GLsizei count, GLenum mode)
{
	glDrawElements(mode, count, GL_UNSIGNED_INT, 0);
}
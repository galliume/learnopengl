#include "Renderer.h"

void Renderer::Clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawArrays(unsigned int VAO, GLsizei count, GLenum mode)
{
	glDrawArrays(mode, 0, count);
}

void Renderer::DrawElements(unsigned int VAO, GLsizei count, GLenum mode)
{
	glDrawElements(mode, count, GL_UNSIGNED_INT, 0);
}
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer(bool drawAsPolygon)
{
	if (drawAsPolygon)	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OpenGLRenderer::Clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::Draw(int count)
{
	//glDrawArrays(m_Mode, 0, count);
	glDrawElements(m_Mode, count, GL_UNSIGNED_INT, 0);
}
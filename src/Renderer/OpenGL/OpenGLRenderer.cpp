#include "OpenGLRenderer.h"

void OpenGLMessageCallback(
	unsigned source,
	unsigned type,
	unsigned id,
	unsigned severity,
	int length,
	const char* message,
	const void* userParam)
{
	//@todo use spdlog
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		std::cout << "[HIGH] " << message << std::endl;
		return;
	case GL_DEBUG_SEVERITY_MEDIUM:
		std::cout << "[MEDIUM] " << message << std::endl;
		return;
	case GL_DEBUG_SEVERITY_LOW:
		std::cout << "[LOW] " << message << std::endl;
		return;
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		std::cout << "[NOTIFICATION] " << message << std::endl;
		return;
	}
}

OpenGLRenderer::OpenGLRenderer(bool drawAsPolygon, bool debugMode)
{
	if (drawAsPolygon)	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (debugMode)
	{
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
	}

	std::cout << "API : OpenGL" << std::endl;
	std::cout << "Vendor " << (const char*)glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer " << (const char*)glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version " << (const char*)glGetString(GL_VERSION) << std::endl;
	std::cout << "ShadingLanguageVersion " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
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
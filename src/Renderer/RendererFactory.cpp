#include "RendererFactory.h"
#include "OpenGL/OpenGLRenderer.h"

AbstractRenderer* RendererFactory::GetRenderer()
{
	switch (RENDERER)
	{
	case 0:
		return new OpenGLRenderer();
		break;
	default:
		return new OpenGLRenderer();
		break;
	}
}

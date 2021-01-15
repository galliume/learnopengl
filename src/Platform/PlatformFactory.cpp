#include "PlatformFactory.h"
#include "GLFW/GLFWWindow.h"

AbstractWindow* PlatformFactory::GetPlatform(int width, int height, std::string name)
{	
	switch (PLATFORM)
	{
	case 0:	
		return new GLFWWindow(width, height, name, 4, 6);
		break;
	default:
		return new GLFWWindow(width, height, name, 4, 6);
		break;
	}
}
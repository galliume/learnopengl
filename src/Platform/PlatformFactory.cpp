#include "PlatformFactory.h"
#include "GLFW/GLFWWindow.h"

AbstractWindow* PlatformFactory::GetPlatform(int width, int height, std::string name)
{	
	switch (PLATFORM)
	{
	case 0:	
		return &GLFWWindow(width, height, name, 4, 6);
		break;
	default:
		return &GLFWWindow(width, height, name, 4, 6);
		break;
	}
}
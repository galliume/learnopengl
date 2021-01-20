#pragma once
#include <string>

#include <glad/glad.h>
#include "../Platform/PlatformFactory.h"
#include "../Renderer/RendererFactory.h"

class App
{
public:
	App(int width, int height, std::string name);
	void Run();
private:
	AbstractWindow* m_Window = nullptr;
	AbstractRenderer* m_Renderer = nullptr;
};
#pragma once
#include <string>

#include <glad/glad.h>
#include "../Platform/PlatformFactory.h"

class App
{
public:
	App(int width, int height, std::string name);
	void Run();
private:
	AbstractWindow* window = nullptr;
};
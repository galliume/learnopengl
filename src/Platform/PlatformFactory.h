#pragma once

#include <string>

#include "Rebi/rebipch.h"
#include "Platform/Abstract/AbstractWindow.h"

class PlatformFactory
{
public:
	static AbstractWindow* GetPlatform(int width, int height, std::string name);
};
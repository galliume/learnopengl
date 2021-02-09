#pragma once

#include "Rebi/rebipch.h"
#include "Abstract/AbstractRenderer.h"

class RendererFactory
{
public:
	static AbstractRenderer* GetRenderer();
};
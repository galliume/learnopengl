#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

class Texture 
{
public:
	Texture(const char* texturePath);
	unsigned int GetTexture() { return m_Texture; };
private:
	unsigned int m_Texture;
};
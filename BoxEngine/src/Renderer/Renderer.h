#pragma once
#include <cstdint>

class Renderer
{
public:
	static void drawElements(uint32_t count);
	static void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
public:
	static bool initialize();
};

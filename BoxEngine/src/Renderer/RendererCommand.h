#pragma once
#include <cstdint>

class RendererCommand
{
public:
	static bool initialize();
	static void setClearColor(float r, float g, float b, float a);
	static void clear();
	static void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	static void drawElements(uint32_t count);
};

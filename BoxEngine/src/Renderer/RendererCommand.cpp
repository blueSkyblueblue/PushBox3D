#include "RendererCommand.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

bool RendererCommand::initialize()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return false;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void RendererCommand::setClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void RendererCommand::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererCommand::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	glViewport(x, y, width, height);
}

void RendererCommand::drawElements(uint32_t count)
{
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}


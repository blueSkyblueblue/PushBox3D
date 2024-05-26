#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>


void Renderer::drawElements(uint32_t count)
{
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}

void Renderer::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	glViewport(x, y, width, height);
}

bool Renderer::initialize()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return false;
	return true;
}

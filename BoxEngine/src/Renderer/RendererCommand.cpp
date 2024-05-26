#include "RendererCommand.h"
#include <glad/glad.h>


void RendererCommand::setClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void RendererCommand::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

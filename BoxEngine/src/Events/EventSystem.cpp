#include "EventSystem.h"
#include <GLFW/glfw3.h>

void EventSystem::pollEvents()
{
	glfwPollEvents();
}

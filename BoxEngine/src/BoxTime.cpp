#include "BoxTime.h"
#include <GLFW/glfw3.h>

float BoxTime::currentTime()
{
	return (float)glfwGetTime();
}

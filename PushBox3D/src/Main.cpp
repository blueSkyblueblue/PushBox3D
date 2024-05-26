#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Window.h"

#include <iostream>


int main()
{
	WindowSpecification spec;
	spec.Name = "Testing";
	spec.Width = 1500;
	spec.Height = 1200;

	if (!Window::initialize()) return -1;

	Window window(spec);

	glfwSetKeyCallback(window.expose(),
		[](GLFWwindow* window, int key, int scancode, int action, int mod)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		});

	glfwMakeContextCurrent(window.expose());
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -3;

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!glfwWindowShouldClose(window.expose()))
	{
		glClearColor(0.125f, 0.124f, 0.132f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window.expose());
		glfwPollEvents();
	}

	glfwTerminate();
}
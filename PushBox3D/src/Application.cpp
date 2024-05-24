#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>


int main()
{
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(1200, 900, "Testing", nullptr, nullptr);
	if (!window) return -2;

	glfwSetKeyCallback(window, 
		[](GLFWwindow* window, int key, int scancode, int action, int mod) 
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GLFW_TRUE);
		});

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -3;

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.125f, 0.124f, 0.132f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

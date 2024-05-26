#include "Window.h"
#include <GLFW/glfw3.h>
#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

static void glfwErrorCallback(int code, const char* description);

static void windowCloseCallback(GLFWwindow* window);
static void windowResizeCallback(GLFWwindow* window, int width, int height);
static void windowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void windowMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
static void windowMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
static void windowCursorPosCallback(GLFWwindow* window, double xpos, double ypos);
static void windowCharCallback(GLFWwindow* window, int codepoint);

bool Window::initialize()
{
	glfwSetErrorCallback(glfwErrorCallback);
	if (!glfwInit()) return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
	
	return true;
}

class OpenGLWindow : public Window
{
public:
	OpenGLWindow(const WindowSpecification& spec);
	virtual ~OpenGLWindow() override;

	OpenGLWindow(OpenGLWindow&&) = delete;
	OpenGLWindow(const OpenGLWindow&) = delete;

	virtual void makeContextCurrent() const override;
	virtual void swapBuffers() const override;
	virtual void setVSync(bool vSync) override;
	virtual bool isVSync() const override { return m_Specification.VSync; }
	virtual std::pair<uint32_t, uint32_t> size() const override;

	virtual void loadEventHandler(const EventHandler& handler) override 
	{
		m_EventHandler = handler;
	};

	virtual void* expose() override { return m_Window; }
	virtual const  void* expose() const override { return m_Window; }
private:
	void initEventHandler() const;
private:
	friend void windowCloseCallback(GLFWwindow* window);
	friend void windowResizeCallback(GLFWwindow* window, int width, int height);
	friend void windowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void windowMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	friend void windowMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	friend void windowCursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	friend void windowCharCallback(GLFWwindow* window, int codepoint);
private:
	GLFWwindow* m_Window;
	WindowSpecification m_Specification;
	EventHandler m_EventHandler;
};


OpenGLWindow::OpenGLWindow(const WindowSpecification& spec)
	: m_Specification { spec }, m_Window { nullptr }
{
	GLFWmonitor* monitor = nullptr;
	if (spec.Fullscreen)
	{
		monitor = glfwGetPrimaryMonitor();
	}

	m_Window = glfwCreateWindow(spec.Width, spec.Height, spec.Name.c_str(), monitor, nullptr);

	if (spec.Maximized)
	{
		glfwMaximizeWindow(m_Window);
	}

	glfwSetWindowUserPointer(m_Window, this);
	initEventHandler();
}

OpenGLWindow::~OpenGLWindow()
{
	glfwDestroyWindow(m_Window);
}

void OpenGLWindow::makeContextCurrent() const
{
	glfwMakeContextCurrent(m_Window);
	if (m_Specification.VSync) glfwSwapInterval(1);
}

void OpenGLWindow::swapBuffers() const
{
	glfwSwapBuffers(m_Window);
}

void OpenGLWindow::setVSync(bool vSync)
{
	glfwSwapInterval(vSync);
	m_Specification.VSync = vSync;
}

std::pair<uint32_t, uint32_t> OpenGLWindow::size() const
{
	return { m_Specification.Width, m_Specification.Height };
}

void OpenGLWindow::initEventHandler() const
{
	glfwSetWindowCloseCallback(m_Window, windowCloseCallback);
	glfwSetWindowSizeCallback(m_Window, windowResizeCallback);
	glfwSetKeyCallback(m_Window, windowKeyCallback);
	glfwSetMouseButtonCallback(m_Window, windowMouseButtonCallback);
	glfwSetScrollCallback(m_Window, windowMouseScrollCallback);
	glfwSetCursorPosCallback(m_Window, windowCursorPosCallback);
}

// =========================================================== //
Window* Window::create(const WindowSpecification& spec)
{
	return new OpenGLWindow(spec);
}
////////////////////////////////////////////////////////////////

static void glfwErrorCallback(int code, const char* description)
{
	printf("GLFW Errors: \n\t%d, \n\t%s", code, description);
}

void windowCloseCallback(GLFWwindow* window)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;
	WindowCloseEvent e;
	handler(e);
}

void windowResizeCallback(GLFWwindow* window, int width, int height)
{
	OpenGLWindow& inst = *(OpenGLWindow*)glfwGetWindowUserPointer(window);
	inst.m_Specification.Width = width;
	inst.m_Specification.Height = height;
	WindowResizeEvent e = { width, height };
	inst.m_EventHandler(e);
}

void windowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;
	
	switch (action)
	{
		case GLFW_PRESS:
		{
			KeyPressEvent e = { key, false, mods };
			handler(e);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressEvent e = { key, true, mods };
			handler(e);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleaseEvent e = { key, mods };
			handler(e);
			break;
		}
	}
}

void windowMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;

	switch (action)
	{
		case GLFW_PRESS:
		{
			MousePressEvent e = { button, mods };
			handler(e);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseReleaseEvent e = { button, mods };
			handler(e);
			break;
		}
	}
}

void windowMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;

	MouseScrollEvent e = { (int)xoffset, (int)yoffset };
	handler(e);

	printf("Mouse Scroll: (%f, %f)\n", xoffset, yoffset);
}

void windowCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;
	
	MouseMoveEvent e = { (int)xpos, (int)ypos };
	handler(e);

	printf("Cursor Pos: { %f, %f }\n", xpos, ypos);
}

void windowCharCallback(GLFWwindow* window, int codepoint)
{
	Window::EventHandler& handler = ((OpenGLWindow*)glfwGetWindowUserPointer(window))->m_EventHandler;
	// TODO...
}


#include "Application.h"
#include "Renderer/Renderer.h"
#include "Renderer/RendererCommand.h"
#include "Events/EventSystem.h"
#include "BoxTime.h"

#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Shader.h"

#define BIND_FUNCTION(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

Application* Application::create()
{
	return s_Instance;
}

Application::Application()
	: m_LastFrameTime { 0.f }
{
	s_Instance = this;
	WindowSpecification spec;
	spec.Name = "Push Box 3D";
	spec.Width = 1500;
	spec.Height = 1200;
	if (!Window::initialize()) __debugbreak();
	m_Window = Window::create(spec);
	m_Window->loadEventHandler(BIND_FUNCTION(Application::onEvent));
	m_Window->makeContextCurrent();
	if (!RendererCommand::initialize()) __debugbreak();
}

Application::~Application()
{
	delete m_Window;
}

void Application::run()
{
	m_Running = true;
	m_LastFrameTime = BoxTime::currentTime();
	Timestep ts = 0.f;
	while (m_Running)
	{
		ts = BoxTime::currentTime() - m_LastFrameTime;
		m_LastFrameTime = BoxTime::currentTime();

		RendererCommand::setClearColor(0.125f, 0.124f, 0.132f, 1.f);
		RendererCommand::clear();

		//
		// Rendering (attach some layers or levels to rendering thing on the screen)
		for (Layer* layer : m_LayerStack)
			layer->onUpdate(ts);
		//
		//

		m_Window->swapBuffers();
		EventSystem::pollEvents();
	}
}

void Application::close()
{
	m_Running = false;
}

void Application::pushLayer(Layer* layer)
{
	m_LayerStack.pushLayer(layer);
	layer->onAttach();
}

void Application::popLayer(Layer* layer)
{
	m_LayerStack.popLayer(layer);
	layer->onDetach();
}

void Application::pushOverlay(Layer* overlay)
{
	m_LayerStack.pushOverlay(overlay);
	overlay->onDetach();
}

void Application::popOverlay(Layer* overlay)
{
	m_LayerStack.popOverlay(overlay);
	overlay->onDetach();
}

void Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(BIND_FUNCTION(Application::onWindowClose));
	dispatcher.dispatch<WindowResizeEvent>(BIND_FUNCTION(Application::onWindowResize));

	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	{
		if (e.Handled) break;
		(*it)->onEvent(e);
	}
}

std::pair<uint32_t, uint32_t> Application::getWindowSize() const
{
	return m_Window->size();
}

Application* Application::get()
{
	return s_Instance;
}

bool Application::onWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

bool Application::onWindowResize(WindowResizeEvent& e)
{
	//if (e.Width == 0 || e.Height == 0)
	//{
	//	m_Minimized = true;
	//	return false;
	//}

	//m_Minimized = false;
	//Renderer::onWindowResize(e.Width, e.Height);

	return false;
}

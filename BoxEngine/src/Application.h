#pragma once
#include "Window.h"
#include "LayerStack.h"
#include "Events/WindowEvent.h"

class Application // singleton
{
public:
	Application();
	~Application();
	void run();
	void close();
	void pushLayer(Layer* layer);
	void popLayer(Layer* layer);
	void pushOverlay(Layer* overlay);
	void popOverlay(Layer* overlay);
	void onEvent(Event& e);
	Window& getWindow() { return *m_Window; }
	const Window& getWindow() const { return *m_Window; }
	std::pair<uint32_t, uint32_t> getWindowSize() const;
	static Application* get();
	static Application* create();
private:
	bool onWindowClose(WindowCloseEvent& e);
	bool onWindowResize(WindowResizeEvent& e);
	Application(Application&&) = default;
	Application(const Application&) = default;
private:
	LayerStack m_LayerStack;
	float m_LastFrameTime;
	bool m_Running = false;
	Window* m_Window = nullptr;
private:
	static Application* s_Instance;
};
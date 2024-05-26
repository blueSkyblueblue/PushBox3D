#pragma once
#include <string>
#include <functional>
#include "Events/Event.h"

struct WindowSpecification
{
	uint32_t Width = 1200;
	uint32_t Height = 900;
	std::string Name = "Test";
	bool Fullscreen = false;
	bool Maximized = false;
	bool Minimized = false;
	bool VSync = true;
};

class Window
{
public:
	virtual ~Window() {};

	virtual void makeContextCurrent() const = 0;
	virtual void swapBuffers() const = 0;
	virtual void setVSync(bool vSync) = 0;
	virtual bool isVSync() const = 0;
	virtual std::pair<uint32_t, uint32_t> size() const = 0;

	using EventHandler = std::function<void(Event&)>;
	virtual void loadEventHandler(const EventHandler& handler) = 0;

	virtual void* expose() = 0;
	virtual const  void* expose() const = 0;
public:
	static bool initialize();
	static Window* create(const WindowSpecification& spec);
};

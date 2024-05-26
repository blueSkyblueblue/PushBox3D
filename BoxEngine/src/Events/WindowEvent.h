#pragma once
#include "Event.h"

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(int width, int height)
		: Width { (uint32_t)width }, Height { (uint32_t)height }
	{
	}

	virtual EventType getEventType() const override { return EventType::WindowResizeEvent; }
	static EventType getStaticType() { return EventType::WindowResizeEvent; }

	uint32_t Width, Height;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() {}

	virtual EventType getEventType() const override { return EventType::WindowCloseEvent; }
	static EventType getStaticType() { return EventType::WindowCloseEvent; }
};

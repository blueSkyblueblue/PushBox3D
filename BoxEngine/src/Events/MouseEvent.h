#pragma once
#include "Event.h"

class MousePressEvent : public Event
{
public:
	MousePressEvent(int button, int mods)
		: Button { button }, Mods { mods }
	{
	}

	virtual EventType getEventType() const override { return EventType::MousePressEvent; }
	static EventType getStaticType() { return EventType::MousePressEvent; }

	int Button, Mods;
};

class MouseReleaseEvent : public Event
{
public:
	MouseReleaseEvent(int button, int mods)
		: Button{ button }, Mods{ mods }
	{
	}

	virtual EventType getEventType() const override { return EventType::MouseReleaseEvent; }
	static EventType getStaticType() { return EventType::MouseReleaseEvent; }

	int Button, Mods;
};

class MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(int xpos, int ypos)
		: Xpos { xpos }, Ypos { ypos }
	{
	}
	
	virtual EventType getEventType() const override { return EventType::MouseMoveEvent; }
	static EventType getStaticType() { return EventType::MouseMoveEvent; }

	int Xpos, Ypos;
};

class MouseScrollEvent : public Event
{
public:
	MouseScrollEvent(int xoffset, int yoffset)
		: Xoffset { xoffset }, Yoffset {  yoffset }
	{
	}
	
	virtual EventType getEventType() const override { return EventType::MouseScrollEvent; }
	static EventType getStaticType() { return EventType::MouseScrollEvent; }

	int Xoffset, Yoffset;
};
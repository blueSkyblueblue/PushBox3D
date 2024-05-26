#pragma once
#include "Event.h"

class KeyPressEvent : public Event
{
public:
	KeyPressEvent(int key, bool repeated, int mods)
		: Key { key }, IsRepeated { repeated }, Mods { mods }
	{
	}

	virtual EventType getEventType() const override { return EventType::KeyPressEvent; }
	static EventType getStaticType() { return EventType::KeyPressEvent; }

	int Key, Mods;
	bool IsRepeated;
};

class KeyReleaseEvent : public Event
{
public:
	KeyReleaseEvent(int key, int mods)
		: Key{ key }, Mods{ mods }
	{
	}

	virtual EventType getEventType() const override { return EventType::KeyReleaseEvent; }
	static EventType getStaticType() { return EventType::KeyReleaseEvent; }

	int Key, Mods;
};

class KeyTypeEvent : public Event
{
public:
	KeyTypeEvent(unsigned int code)
		: Codepoint { code }
	{
	}

	virtual EventType getEventType() const override { return EventType::KeyTypeEvent; }
	static EventType getStaticType() { return EventType::KeyTypeEvent; }

	unsigned int Codepoint;
};
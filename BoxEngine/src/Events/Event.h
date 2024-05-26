#pragma once

enum class EventType : unsigned char
{
	WindowEvent, MouseEvent, KeyEvent,
	WindowResizeEvent, WindowCloseEvent,
	MousePressEvent, MouseReleaseEvent, MouseMoveEvent, MouseScrollEvent,
	KeyPressEvent, KeyReleaseEvent, KeyTypeEvent
};

class Event
{
public:
	~Event() {};
	virtual EventType getEventType() const = 0;

	bool Handled = false;
};

class EventDispatcher
{
public:
	EventDispatcher(Event& e)
		: m_Event { e }
	{
	}
	
	~EventDispatcher() {}

	template <typename T, typename F>
	bool dispatch(const F& handle)
	{
		if (m_Event.getEventType() == T::getStaticType())
		{
			m_Event.Handled |= handle(static_cast<T&>(m_Event));
			return true;
		}

		return false;
	}
private:
	Event& m_Event;
};
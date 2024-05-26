#pragma once

class Timestep
{
public:
	Timestep(float duration = 0.f)
		: m_Duration { duration }
	{
	}

	void operator=(float duration) { m_Duration = duration; }
	operator float() const { return m_Duration; }
	float get() const { return m_Duration; }
	float toMilliseconds() const { return m_Duration * 1000.f; }
private:
	float m_Duration;
};
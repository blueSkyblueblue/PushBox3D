#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
	Camera(const glm::mat4& projection) 
		: m_Projection { projection }, m_View { glm::mat4(1.f) }
	{
	}

	virtual ~Camera() {};
	virtual const glm::mat4& view() const { return m_View; };
	virtual const glm::mat4& projection() const { return m_Projection; };
	virtual void transform(const glm::mat4& transform) = 0;
protected:
	glm::mat4 m_Projection;
	glm::mat4 m_View;
};
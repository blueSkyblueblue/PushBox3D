#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far)
	: Camera { glm::perspective(fov, aspect, far, near) },
	m_Yaw { 0.f }, m_Pitch { 0.f },
	m_Fov { fov }, m_AspectRatio { aspect }, m_Far { far }, m_Near { near },
	m_Position { 0.f, 0.f, 0.f }, m_Direction{0.f, 0.f, -1.f}
{
}

void PerspectiveCamera::transform(const glm::mat4& transform)
{
	m_Direction = glm::mat3(transform) * m_Direction;
	m_View = glm::inverse(transform) * m_View;
	glm::vec3 horizontalDirection = { m_Direction.x, 0.f, m_Direction.z };

	if (horizontalDirection.length() == 0.f)
		m_Pitch = glm::radians(90.f);
	else
	{
		horizontalDirection = glm::normalize(horizontalDirection);
		m_Yaw = acos(glm::dot(horizontalDirection, { 0.f, 0.f, -1.f }));
		m_Pitch = acos(glm::dot(m_Direction, horizontalDirection));
	}
}

void PerspectiveCamera::setPosition(const glm::vec3& position)
{
	m_Position = position;
	m_View = glm::lookAt(m_Position, m_Position + m_Direction, { 0.f, 1.f, 0.f });
}

void PerspectiveCamera::setDirection(const glm::vec3& direction)
{
	m_Direction = direction;
	m_View = glm::lookAt(m_Position, m_Position + m_Direction, { 0.f, 1.f, 0.f });

}

void PerspectiveCamera::setAspectRatio(float aspect)
{
	m_AspectRatio = aspect;
	m_Projection = glm::perspective(m_Fov, m_AspectRatio, m_Near, m_Far);
}


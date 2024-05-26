#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far)
	: Camera { glm::perspective(fov, aspect, far, near) },
	m_Fov { fov }, m_AspectRatio { aspect }, m_Far { far }, m_Near { near }
{
}

PerspectiveCamera::PerspectiveCamera(float left, float right, float bottom, float top, float near, float far)
	: Camera { glm::frustum(left, right, bottom, top, near, far) },
	m_Far { far }, m_Near{ near },
	m_Fov { glm::degrees(atan((right - left) / (2 * far))) },
	m_AspectRatio { (right - left) / (top - bottom) }
{
}

void PerspectiveCamera::transform(const glm::mat4& transform)
{
	m_Direction = glm::mat3(transform) * m_Direction;
	m_Position = transform * glm::vec4(m_Position, 1.f);
	m_View = glm::inverse(transform) * m_View;
	glm::vec3 horizontalDirection = { m_Direction.x, 0.f, m_Direction.z };

	if (horizontalDirection.length() == 0.f)
		m_Pitch = glm::radians(90.f);
	else
	{
		horizontalDirection = glm::normalize(horizontalDirection);
		m_Yaw = acos(glm::dot(horizontalDirection, { 0.f, 0.f, -1.f }));
		m_Pitch = acos(glm::dot(m_Direction, horizontalDirection));

		m_Yaw = m_Direction.x > 0 ? m_Yaw : -m_Yaw;
		m_Pitch = m_Direction.y > 0 ? m_Pitch : -m_Pitch;
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
	glm::vec3 horizontalDirection = { m_Direction.x, 0.f, m_Direction.z };

	if (horizontalDirection.length() == 0.f)
		m_Pitch = glm::radians(90.f);
	else
	{
		horizontalDirection = glm::normalize(horizontalDirection);
		m_Yaw = acos(glm::dot(horizontalDirection, { 0.f, 0.f, -1.f }));
		m_Pitch = acos(glm::dot(m_Direction, horizontalDirection));

		m_Yaw = m_Direction.x > 0 ? m_Yaw : -m_Yaw;
		m_Pitch = m_Direction.y > 0 ? m_Pitch : -m_Pitch;
	}
}

void PerspectiveCamera::setAspectRatio(float aspect)
{
	m_AspectRatio = aspect;
	m_Projection = glm::perspective(m_Fov, m_AspectRatio, m_Near, m_Far);
}


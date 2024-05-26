#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far)
	: Camera { glm::ortho(left, right, bottom, top, near, far) },
	m_Left { left }, m_Right { right }, m_Bottom { bottom }, m_Top { top },
	m_Near { near }, m_Far { far }
{
}

void OrthographicCamera::transform(const glm::mat4& transform)
{
	m_View = glm::inverse(transform) * m_View;
	m_Position = transform * glm::vec4(m_Position, 1.f);
	m_Direction = glm::mat3(transform) * m_Direction;
}

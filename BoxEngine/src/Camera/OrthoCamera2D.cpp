#include "OrthoCamera2D.h"
#include <glm/gtc/matrix_transform.hpp>

OrthoCamera2D::OrthoCamera2D(float left, float right, float bottom, float top)
	: Camera { glm::ortho(left, right, bottom, top) }
{
}

void OrthoCamera2D::transform(const glm::mat4& transform)
{
	m_View = glm::inverse(transform) * m_View;
	m_Direction = glm::mat2(transform) * m_Direction;
	m_Rotation = acos(glm::dot(m_Direction, glm::vec2(0.f, 1.f)));
	m_Rotation = m_Direction.x > 0 ? -m_Rotation : m_Rotation;
}

void OrthoCamera2D::rotate(float angle)
{
	m_View = glm::rotate(glm::mat4(1.f), -angle, { 0.f, 0.f, 1.f }) * m_View;
	m_Direction = glm::rotate(glm::mat4(1.f), angle, { 0.f, 0.f, 1.f }) * glm::vec4(m_Direction, 0.f, 1.f);
	m_Rotation += glm::radians(angle);
}

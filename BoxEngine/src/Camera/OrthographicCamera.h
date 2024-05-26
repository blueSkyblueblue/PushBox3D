#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera
{
public:
	OrthographicCamera(float left, float right, float bottom, float top, float near = -1.f, float far = 1.f);
	virtual ~OrthographicCamera() {}

	virtual void transform(const glm::mat4& transform) override;
private:
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Far, m_Near;

	glm::vec3 m_Position = { 0.f, 0.f, 0.f };
	glm::vec3 m_Direction = { 0.f, 0.f, -1.f };
};
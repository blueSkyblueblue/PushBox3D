#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera(float fov, float aspect, float near, float far);
	virtual ~PerspectiveCamera() {}

	virtual glm::vec3& direction() { return m_Direction; };
	virtual const glm::vec3& direction() const { return m_Direction; };
	virtual void transform(const glm::mat4& transform) override;
	
	void setPosition(const glm::vec3& position);
	void setDirection(const glm::vec3& direction);
	void setAspectRatio(float aspect);
private:
	float m_Yaw, m_Pitch;
	float m_Fov;
	float m_AspectRatio;
	float m_Far, m_Near;

	glm::vec3 m_Position;
	glm::vec3 m_Direction;
};
#pragma once
#include "Camera.h"

class OrthoCamera2D : public Camera
{
public:
	OrthoCamera2D(float left, float right, float bottom, float top);
	virtual ~OrthoCamera2D() {}

	virtual void transform(const glm::mat4& transform) override;
	void rotate(float angle);
private:
	float m_Rotation = 0.f;		// In radians
	glm::vec2 m_Direction = { 0.f, 1.f };
};


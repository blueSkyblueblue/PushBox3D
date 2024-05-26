#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera
{
public:
	OrthographicCamera(float left, float right, float bottom, float top);
	virtual ~OrthographicCamera() {}

private:

};
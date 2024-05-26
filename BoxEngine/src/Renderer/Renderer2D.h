#pragma once
#include "Texture2D.h"

#include <glm/glm.hpp>

class Renderer2D
{
public:
	//static void initialize(const OrthographicCamera& camera);
	static void initialize(float left, float right, float bottom, float top);
	static void resize(float left, float right, float bottom, float top);
	static void rectangle(const glm::mat4& transform, const glm::vec3& color);
	static void rectangle(const glm::mat4& transform, const Texture2D& texture);
	static void rectangle(float x, float y, float width, float height, const glm::vec3& color);
	static void rectangle(float x, float y, float width, float height, const Texture2D& texture);
	static void border(float x, float y, float width, float height, const glm::vec3& color, float lineWidth);
	static void shutdown();
	static bool isInitialized() { return s_Initialized; }

private:
	static bool s_Initialized;
};


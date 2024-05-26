#include "Renderer2D.h"
#include "Shader.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

#define ASSERT_GL_ERROR if(glGetError() != GL_NO_ERROR) __debugbreak()

static glm::mat4 s_Projection = glm::mat4(1.0);

static float quadVertices[16] = {
	// Position, TexCoord
	0.f, 0.f,	0.f, 0.f,
	1.f, 0.f,	1.f, 0.f,
	1.f, 1.f,	1.f, 1.f,
	0.f, 1.f,	0.f, 1.f
};

static uint32_t quadIndices[6] = { 0, 1, 2, 0, 2, 3 };

static uint32_t s_QuadVAO, s_QuadVBO, s_QuadIBO;

static Shader* s_QuadShader = nullptr;
static Texture2D* s_QuadTexture = nullptr;

//void Renderer2D::initialize(const OrthographicCamera& camera)
//{
//	__debugbreak();
//}

bool Renderer2D::s_Initialized = false;

void Renderer2D::initialize(float left, float right, float bottom, float top)
{
	static const std::string quadVertexShader = R"(
		#version 460 core

		layout(location = 0) in vec4 a_Position;
		layout(location = 1) in vec2 a_TexCoord;
	
		out vec2 v_TexCoord;

		uniform mat4 u_Projection;
		uniform mat4 u_Transform;

		void main()
		{
			v_TexCoord = a_TexCoord;
			gl_Position = u_Projection * u_Transform * a_Position;
		}
	)";

	static const std::string quadFragShader = R"(
		#version 460 core

		in vec2 v_TexCoord;

		uniform vec3 u_Color;

		uniform sampler2D u_Texture;

		void main()
		{
			gl_FragColor = texture(u_Texture, v_TexCoord) * vec4(u_Color, 1.0f);
		}
	)";

	glGenVertexArrays(1, &s_QuadVAO);
	glBindVertexArray(s_QuadVAO);
	
	glGenBuffers(1, &s_QuadVBO);
	glBindBuffer(GL_ARRAY_BUFFER, s_QuadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &s_QuadIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_QuadIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0); // Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, (size_t)4 * sizeof(float), 0);

	glEnableVertexAttribArray(1); // TexCoord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, (size_t)4 * sizeof(float), (void*)(sizeof(float) * 2));

	s_QuadShader = new Shader(quadVertexShader, quadFragShader, false);
	s_QuadTexture = new Texture2D(1.0f, 1.0f, 1.0f);
	s_QuadShader->use();
	s_Projection = glm::ortho(left, right, bottom, top);
	s_QuadShader->loadUniformMat4("u_Projection", s_Projection);
	s_QuadShader->loadUniformMat4("u_Transform", glm::mat4(1.0f));
	s_QuadShader->loadUniform3f("u_Color", 1.f, 1.f, 1.f);
	s_QuadTexture->bind();
	s_QuadShader->loadUniform1i("u_Texture", 0);

	s_Initialized = true;
}

void Renderer2D::resize(float left, float right, float bottom, float top)
{
	s_QuadShader->use();
	s_Projection = glm::ortho(left, right, bottom, top);
	s_QuadShader->loadUniformMat4("u_Projection", s_Projection);
}

void Renderer2D::rectangle(const glm::mat4& transform, const glm::vec3& color)
{
	glBindVertexArray(s_QuadVAO);
	s_QuadShader->use();
	s_QuadShader->loadUniformMat4("u_Transform", transform);
	s_QuadShader->loadUniform3fv("u_Color", color);
	s_QuadTexture->bind();
	s_QuadShader->loadUniform1i("u_Texture", 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Renderer2D::rectangle(const glm::mat4& transform, const Texture2D& texture)
{
	glBindVertexArray(s_QuadVAO);
	s_QuadShader->use();
	s_QuadShader->loadUniformMat4("u_Transform", transform);
	s_QuadShader->loadUniform3f("u_Color", 1.f, 1.f, 1.f);
	texture.bind();
	s_QuadShader->loadUniform1i("u_Texture", 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Renderer2D::rectangle(float x, float y, float width, float height, const glm::vec3& color)
{
	glm::mat4 s_Transform = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f))
		* glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));

	rectangle(s_Transform, color);
}

void Renderer2D::rectangle(float x, float y, float width, float height, const Texture2D& texture)
{
	glm::mat4 s_Transform = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f))
		* glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));

	rectangle(s_Transform, texture);
}

void Renderer2D::border(float x, float y, float width, float height, const glm::vec3& color, float lineWidth)
{
	rectangle(x, y, lineWidth, height, color);
	rectangle(x + width - lineWidth, y, lineWidth, height, color);
	rectangle(x, y, width, lineWidth, color);
	rectangle(x, y + height - lineWidth, width, lineWidth, color);
}

void Renderer2D::shutdown()
{
	glDeleteVertexArrays(1, &s_QuadVAO);
	glDeleteBuffers(1, &s_QuadVBO);
	glDeleteBuffers(1, &s_QuadIBO);
}

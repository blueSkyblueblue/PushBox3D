#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray()
	: m_RendererID { 0 }
{
	glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_RendererID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

#include "VertexBuffer.h"
#include <glad/glad.h>

static int getComponentCount(VertexElement elem);
static int getElementSize(VertexElement elem);
static int getElementGLType(VertexElement elem);

void VertexAttribLayout::clear()
{
	m_Layout.clear();
}

void VertexAttribLayout::erase(uint32_t index)
{
	m_Layout.erase(m_Layout.begin() + index);
}

void VertexAttribLayout::push(VertexElement elem)
{
	m_Layout.push_back(elem);
}

VertexBuffer::VertexBuffer()
	: m_RendererID { 0 }
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

VertexBuffer::VertexBuffer(void* vertices, uint32_t size)
	: m_RendererID { 0 }
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::loadVertices(void* vertices, uint32_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::loadLayout(const VertexAttribLayout& layout)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);

	int stride = 0;
	for (auto attrib : layout) stride += getElementSize(attrib);

	uint32_t index = 0;
	uint32_t pointer = 0;
	for (auto attrib : layout)
	{
		GLboolean normalized = attrib == VertexElement::BYTE ? GL_TRUE : GL_FALSE;
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, getComponentCount(attrib), getElementGLType(attrib), normalized, stride, (void*)(uint64_t)pointer);
		pointer += getElementSize(attrib);
		index++;
	}
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int getComponentCount(VertexElement elem)
{
	switch (elem)
	{
		case VertexElement::BOOL:	return 1;
		case VertexElement::BYTE:	return 1;
		case VertexElement::INT:	return 1;
		case VertexElement::INT2:	return 2;
		case VertexElement::INT3:	return 3;
		case VertexElement::INT4:	return 4;
		case VertexElement::FLOAT:	return 1;
		case VertexElement::FLOAT2: return 2;
		case VertexElement::FLOAT3: return 3;
		case VertexElement::FLOAT4:	return 4;
	}

	return 0;
}

int getElementSize(VertexElement elem)
{
	switch (elem)
	{
		case VertexElement::BOOL:	return 1;
		case VertexElement::BYTE:	return 1;
		case VertexElement::INT:	return 4;
		case VertexElement::INT2:	return 8;
		case VertexElement::INT3:	return 12;
		case VertexElement::INT4:	return 16;
		case VertexElement::FLOAT:	return 4;
		case VertexElement::FLOAT2: return 8;
		case VertexElement::FLOAT3: return 12;
		case VertexElement::FLOAT4:	return 16;
	}

	return 0;
}

int getElementGLType(VertexElement elem)
{
	switch (elem)
	{
		case VertexElement::BOOL:	return GL_BOOL;
		case VertexElement::BYTE:	return GL_BYTE;
		case VertexElement::INT:	return GL_INT;
		case VertexElement::INT2:	return GL_INT;
		case VertexElement::INT3:	return GL_INT;
		case VertexElement::INT4:	return GL_INT;
		case VertexElement::FLOAT:	return GL_FLOAT;
		case VertexElement::FLOAT2: return GL_FLOAT;
		case VertexElement::FLOAT3: return GL_FLOAT;
		case VertexElement::FLOAT4:	return GL_FLOAT;
	}

	return 0;
}

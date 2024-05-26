#pragma once
#include <cstdint>

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(uint32_t* indices, uint32_t size);
	~IndexBuffer();

	void loadIndices(uint32_t* indices, uint32_t size);
	void bind();
	void unbind();
private:
	uint32_t m_RendererID;
};

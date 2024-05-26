#pragma once
#include <vector>

enum class VertexElement : unsigned char
{
	NONE,
	BOOL, BYTE,
	INT, INT2, INT3, INT4,
	FLOAT, FLOAT2, FLOAT3, FLOAT4,
};

class VertexAttribLayout
{
public:
	VertexAttribLayout() = default;
	~VertexAttribLayout() {}

	void clear();
	void erase(uint32_t index);
	void push(VertexElement elem);
	size_t count() const { return m_Layout.size(); }
	const std::vector<VertexElement>& get() const { return m_Layout; }

	std::vector<VertexElement>::const_iterator begin() const { return m_Layout.begin(); };
	std::vector<VertexElement>::const_iterator end() const { return m_Layout.end(); };
private:
	std::vector<VertexElement> m_Layout;
};

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(void* vertices, uint32_t size);
	~VertexBuffer();
	
	void loadVertices(void* vertices, uint32_t size);
	void loadLayout(const VertexAttribLayout& layout);
	void bind();
	void unbind();
private:
	uint32_t m_RendererID;
};

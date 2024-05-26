#pragma once
#include <string>

class Texture2D
{
public:
	Texture2D(const std::string& imgPath);
	Texture2D(float r, float g, float b);
	~Texture2D();

	void bind(uint32_t slot = 0) const;
	int id() const { return m_TextureID; }
private:
	int m_Width, m_Height, m_Channels;
	int m_InternalFormat, m_DataFormat;
	uint32_t m_TextureID = 0;
};
#include "Texture2D.h"
#include <glad/glad.h>
#include <stb_image.h>


Texture2D::Texture2D(const std::string& imgPath)
{
	stbi_set_flip_vertically_on_load(1);
	stbi_uc* img = stbi_load(imgPath.c_str(), &m_Width, &m_Height, &m_Channels, 0);

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	if (m_Channels == 4)
	{
		m_InternalFormat = GL_RGBA8;
		m_DataFormat = GL_RGBA;
	}
	else
	{
		m_InternalFormat = GL_RGB8;
		m_DataFormat = GL_RGB;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, img);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (img) stbi_image_free(img);
}

Texture2D::Texture2D(float r, float g, float b)
	: m_Width { 1 }, m_Height { 1 }, m_Channels { 3 },
	m_InternalFormat { GL_RGB8 }, m_DataFormat { GL_RGB }
{
	unsigned char* img = new unsigned char[3];
	img[0] = (unsigned char)(r * 255);
	img[1] = (unsigned char)(g * 255);
	img[2] = (unsigned char)(b * 255);

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, img);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture2D::bind(uint32_t slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

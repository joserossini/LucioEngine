#include "texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"


lucio::Texture::Texture(const std::string & file, TextureType type):
	_type((GLenum)type)
{
	glGenTextures(1, &_texture);
	bind();
	
	setWrap(TextureWrapping::MirroredRepeat);
	setFilter(TextureFilter::Linear);
	setMipMap(MipMap::NearToNear);

	LoadTextureFromFile(file);
}

lucio::Texture::~Texture()
{
	glDeleteTextures(1, &_texture);
}

void lucio::Texture::bind()
{
	glBindTexture(_type, _texture);
}

void lucio::Texture::setMipMap(const MipMap mipmap)
{
	glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, (GLenum)mipmap);
}

void lucio::Texture::setFilter(const TextureFilter filter)
{
	glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, (GLenum)filter);
}

void lucio::Texture::setWrap(const TextureWrapping wrap)
{
	glTexParameteri(_type, GL_TEXTURE_WRAP_S, (GLenum)wrap);
	glTexParameteri(_type, GL_TEXTURE_WRAP_T, (GLenum)wrap);
}


void lucio::Texture::LoadTextureFromFile(const std::string & file)
{
	int width, height, nrChannels;
	unsigned char * data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(_type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(_type);
	}
	else
	{
		std::string info = stbi_failure_reason();
		printf("\tERROR! -> Fail to Load Texture: %s", info.c_str());
	}
	stbi_image_free(data);
}
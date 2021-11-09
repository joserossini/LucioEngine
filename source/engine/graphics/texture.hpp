#pragma once

#include "engine/common.hpp"
#include "GL/glew.h"
#include <string>

namespace lucio{

	enum class TextureWrapping : GLint
	{
		MirroredRepeat = GL_MIRRORED_REPEAT,
		Repeat = GL_REPEAT,
		ClampToEdge = GL_CLAMP_TO_EDGE ,
		ClampToBorder = GL_CLAMP_TO_BORDER,
		ClampToBorder2 = GL_CLAMP_TO_EDGE
	};

	enum class TextureType : GLint
	{
		OneDimension = GL_TEXTURE_1D,
		TwoDimensions = GL_TEXTURE_2D,
		ThreeDimensions = GL_TEXTURE_3D
	};

	enum class TextureFilter : GLint
	{
		Linear = GL_LINEAR,
		Nearest = GL_NEAREST
	};

	enum class MipMap : GLint
	{
		NearToNear = GL_NEAREST_MIPMAP_NEAREST,
		LinearToNear = GL_LINEAR_MIPMAP_NEAREST,
		NearToLinear = GL_NEAREST_MIPMAP_LINEAR,
		LinearToLinear = GL_LINEAR_MIPMAP_LINEAR
	};

	/*
	*	Texture	
	*/

    class Texture
    {
        public:
            Texture(const std::string & file, TextureType type = TextureType::TwoDimensions);
            ~Texture();

            void bind();

			void setMipMap(const MipMap mipmap);
			void setFilter(const TextureFilter filter);
			void setWrap(const TextureWrapping wrap);

        private:
            GLuint _texture;
			GLenum _type;

			void LoadTextureFromFile(const std::string& file);
    };



}
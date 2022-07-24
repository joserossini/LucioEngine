#pragma once

#include "glm/glm.hpp"

namespace lucio{
    
    struct vertex_t{
        glm::fvec3 _position;
		glm::fvec3 _color;
		glm::fvec2 _texture;
		glm::fvec3 _normal;

		vertex_t(
			glm::fvec3 position = { 0.0f, 0.0f, 0.0f },
			glm::fvec3 color = { 0.0f, 0.0f, 0.0f },
			glm::fvec2 texture = { 0.0f, 0.0f },
			glm::fvec3 normal = { 0.0f, 0.0f, 0.0f }) :

			_position(position),
			_color(color),
			_texture(texture),
			_normal(normal)
		{};
	};
	
}
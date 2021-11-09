#pragma once

#include "GL/glew.h"

#include "engine/common.hpp"

namespace lucio {

	/*
	*	Mesh
	*/
	
	class Mesh{
		
		public:
			Mesh(vertex_t * vertices, unsigned int vertSize, unsigned int * indeces, unsigned int indeSize);
			~Mesh();
			
			void bind();

		private:
			void create(vertex_t * vertices, unsigned int vertSize, unsigned int * indeces, unsigned int indeSize);

			GLuint _vbo;
			GLuint _ibo;
			GLuint _vao;

			unsigned int _vertSize;
			unsigned int _indeSize;

	};
	
}
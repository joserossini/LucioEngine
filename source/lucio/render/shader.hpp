#pragma once

#include <string>
#include "GL/glew.h"

namespace lucio {

	/*
	*	Shader
	*	Load Fragment and Vertex shaders from files, compiles and links.
	*	And can set uniforms.
	*/

	class Shader {

		public:
			Shader(const std::string &vfilepath, const std::string &ffilepath);
			Shader(const char &vsource, const char &fsource, const int &vsize, const int &fsize);
			~Shader();

			void bind() const;
			
			void setUniform(GLint location, GLfloat value);
			void setUniform(GLint location, GLfloat value1, GLfloat value2, GLfloat value3);


		private:

			inline void compileShader(GLuint *id, const char *src, const int &size, const GLenum type);
			inline void linkShaders(GLuint &vid, GLuint &fid);

			void checkStatus(GLuint & id, const GLenum type);


		private:
			GLuint _program;

	};

}
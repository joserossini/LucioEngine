#include "shader.hpp"

#include "engine/util/fileReader.hpp"
#include <GL/GL.h>


lucio::Shader::Shader(const std::string & vfilepath, const std::string & ffilepath):
	_program(glCreateProgram())
{
	GLuint vid;
	GLuint fid;

	FileReader vfile(vfilepath);
	FileReader ffile(ffilepath);

	compileShader(&vid, vfile.getData(), vfile.getSize(), GL_VERTEX_SHADER);
	compileShader(&fid, ffile.getData(), vfile.getSize(), GL_FRAGMENT_SHADER);

	linkShaders(vid, fid);

	glDeleteShader(vid);
	glDeleteShader(fid);

}

lucio::Shader::Shader(const char & vsource, const char & fsource, const int & vsize, const int & fsize):
	_program(glCreateProgram())
{
	GLuint vid;
	GLuint fid;

	compileShader(&vid, vsource, vsize, GL_VERTEX_SHADER);
	compileShader(&fid, fsource, fsize, GL_FRAGMENT_SHADER);

	linkShaders(vid, fid);

	glDeleteShader(vid);
	glDeleteShader(fid);
}

lucio::Shader::~Shader()
{
	glDeleteProgram(_program);
}

void lucio::Shader::bind() const
{
	glUseProgram(_program);
}

inline void lucio::Shader::compileShader(GLuint * id, const char & src,const GLint & size, const GLenum type)
{
	*id = glCreateShader(type);

	const char * p_src = &src;

	glShaderSource(*id, 1, &p_src, &size);

	glCompileShader(*id);

	checkStatus(*id, GL_COMPILE_STATUS);

}

inline void lucio::Shader::linkShaders(GLuint & vid, GLuint & fid)
{
	glAttachShader(_program, vid);
	glAttachShader(_program, fid);

	glLinkProgram(_program);

	checkStatus(_program, GL_LINK_STATUS);
}

void lucio::Shader::checkStatus(GLuint & id, GLenum type)
{
	GLint  result = GL_TRUE;
	glGetShaderiv(id, type, &result);
	if (result != GL_TRUE){

		GLint sizelog;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &sizelog);

		GLchar * info = new GLchar[(unsigned int)sizelog++];
		glGetShaderInfoLog(id, sizelog, NULL, info);
		printf("\tERROR! 'shader.cpp' -> %s Shader: %s", type == GL_VERTEX_SHADER ? "Vertex" : "Fragment", info);
	}
	return;
}

void lucio::Shader::setUniform(GLint location, float value)
{
	glProgramUniform1f(_program, location, value);
}


void lucio::Shader::setUniform(GLint location, GLfloat value, GLfloat value2, GLfloat value3)
{
	glProgramUniform3f(_program, location, value, value2, value3);
}

#include "mesh.hpp"

#include "vertex.hpp"

lucio::Mesh::Mesh(vertex_t * vertices, unsigned int vertSize, unsigned int * indeces, unsigned int indeSize)
{
	_vertSize = vertSize;
	_indeSize = indeSize;

	create(vertices, vertSize, indeces, indeSize);
}

lucio::Mesh::~Mesh()
{
	glDeleteBuffers(1, &_vbo);
	glDeleteVertexArrays(1, &_vao);
}

void lucio::Mesh::bind()
{
	glBindVertexArray(_vao);
	// Todo debug mode whit wireframe mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)
	glDrawElements(GL_TRIANGLES, _indeSize, GL_UNSIGNED_INT, 0);
}

void lucio::Mesh::create(vertex_t * vertices, unsigned int vertSize, unsigned int * indeces, unsigned int indeSize)
{

	auto sizeOfVertex = sizeof(vertex_t);

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertSize*sizeOfVertex, vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indeSize*sizeof(unsigned int), indeces, GL_STATIC_DRAW);

	//position
	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, 0);
	auto size = sizeof(glm::vec3);

	//color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (GLvoid*)size);
	size + sizeof(glm::vec3);

	//texture coordinate
	glEnableVertexAttribArray(2); 
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeOfVertex, (GLvoid*)size);
	size + sizeof(glm::vec2);

	//normal
	glEnableVertexAttribArray(3); 
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (GLvoid*)size);
	
}

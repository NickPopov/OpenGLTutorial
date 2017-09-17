#pragma once

#include "glm\glm.hpp"
#include "GL\glew.h"

class Vertex
{
public:
	Vertex(const glm::vec3 &pos);
	virtual ~Vertex();
private:
	glm::vec3 m_pos;
};


class Mesh
{
public:
	Mesh(Vertex *vertices, unsigned int numVertices);
	virtual ~Mesh();

	void Draw();

private:
	enum
	{
		POSITION_VB,		
		NUM_BUFFERS
	};

	GLuint m_vertextArrayObjects;
	GLuint m_vertextArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};


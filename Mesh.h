#pragma once

#include "glm\glm.hpp"
#include "GL\glew.h"
#include "obj_loader.h"

class Vertex
{
public:
	Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord, const glm::vec3 &normal = glm::vec3(0,0,0));
	virtual ~Vertex();
//private:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};


class Mesh
{
public:
	Mesh(const std::string &fileName);
	Mesh(Vertex *vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices);	
	virtual ~Mesh();

	void Draw();

private:
	void InitMesh(const IndexedModel &model);

	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	GLuint m_vertextArrayObjects;
	GLuint m_vertextArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};


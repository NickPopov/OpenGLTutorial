#include "Mesh.h"
#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;

	glGenVertexArrays(1, &m_vertextArrayObjects);
	glBindVertexArray(m_vertextArrayObjects);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve(numVertices);
	texCoords.reserve(numVertices);

	for (unsigned int i = 0; i < numVertices; i++)
	{
		positions.push_back(vertices[i].pos);
		texCoords.push_back(vertices[i].texCoord);
	}

	glGenBuffers(NUM_BUFFERS, m_vertextArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertextArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	

	glBindBuffer(GL_ARRAY_BUFFER, m_vertextArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertextArrayObjects);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertextArrayObjects);

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0);
}


Vertex::Vertex(const glm::vec3 & pos, const glm::vec2 &texCoord)
{
	this->pos = pos;
	this->texCoord = texCoord;
}

Vertex::~Vertex()
{
}

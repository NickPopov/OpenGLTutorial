#include "Mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;

	glGenVertexArrays(1, &m_vertextArrayObjects);
	glBindVertexArray(m_vertextArrayObjects);

	glGenBuffers(NUM_BUFFERS, m_vertextArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertextArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

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


Vertex::Vertex(const glm::vec3 & pos)
{
	m_pos = pos;
}

Vertex::~Vertex()
{
}

#include "Transform.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm\gtx\transform.hpp"

Transform::Transform(glm::vec3 &position, glm::vec3 &rotation, glm::vec3 &scale):
	m_position(position), m_rotation(rotation), m_scale(scale)
{
}

Transform::~Transform()
{
}

glm::mat4 Transform::GetModel()
{
	glm::mat4 posMatrix = glm::translate(m_position);
	glm::mat4 rotXMatrix = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 rotYMatrix = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 rotZMatrix = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));
	glm::mat4 scaleMatrix = glm::scale(m_scale);

	glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

	glm::mat4 model = posMatrix * rotMatrix * scaleMatrix;

	return model;
}

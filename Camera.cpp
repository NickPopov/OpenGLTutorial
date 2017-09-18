#include "Camera.h"

Camera::Camera(const glm::vec3 pos, float fov, float aspects, float zNear, float zFar)
{
	m_perspective = glm::perspective(fov, aspects, zNear, zFar);
	m_position = pos;
	m_forward = glm::vec3(0, 0, 1);
	m_up = glm::vec3(0, 1, 0);
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetViewProjection() const
{
	glm::mat4 viewProjection = m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);

	return viewProjection;
}

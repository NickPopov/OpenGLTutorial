#pragma once

#include "glm\glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm\gtx\transform.hpp"

class Camera
{
public:
	Camera(const glm::vec3 pos, float fov, float aspects, float zNear, float zFar);
	virtual ~Camera();
	
	glm::mat4 GetViewProjection() const;
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};


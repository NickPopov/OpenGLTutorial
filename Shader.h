#pragma once

#include <string>

#include "Transform.h"
#include "Camera.h"

#include "GL\glew.h"

class Shader
{
public:
	Shader(const std::string &fileName);
	virtual ~Shader();

	void Bind();
	void Update(Transform &transform, const Camera &camera);	

	static std::string LoadShader(const std::string &fileName);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMassage);
	static GLuint CreateShader(const std::string &text, GLenum shaderType);

private:
	static const unsigned int NUM_SHADERS = 2;

	enum
	{
		TRANSFORM_U,
		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};


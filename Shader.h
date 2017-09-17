#pragma once

#include <string>

#include "GL\glew.h"

class Shader
{
public:
	Shader(const std::string &fileName);
	virtual ~Shader();

	void Bind();

	static std::string LoadShader(const std::string &fileName);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMassage);
	static GLuint CreateShader(const std::string &text, GLenum shaderType);

private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};


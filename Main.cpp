#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

#include "GL\glew.h"

int main(int argc, char** argv)
{
	std::string title = "Hello world";
	Display display(800, 600, title);

	Shader shader("./res/basicShader");
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0),     glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0),  glm::vec2(1.0, 0.0))
	};
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinCounter;
		transform.GetRotation().z = counter;
		transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();		
		texture.Bind(0);
		shader.Update(transform);
		mesh.Draw();
		display.Update();
		counter += 0.001f;
	}
	return 0;
}
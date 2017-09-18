#include <iostream>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#include "GL\glew.h"

int main(int argc, char** argv)
{
	float width = 800;
	float height = 600;
	std::string title = "Hello world";
	Display display(width, height, title);

	Shader shader("./res/basicShader");
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0),     glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0),  glm::vec2(1.0, 0.0))
	};
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture("./res/bricks.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -3), 70.0f, width / height, 0.01f, 1000.0f);	

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinCounter;
		transform.GetRotation().z = counter;		

		shader.Bind();		
		texture.Bind(0);
		shader.Update(transform, camera);
		
		mesh.Draw();
		display.Update();
		counter += 0.0001f;
	}
	return 0;
}
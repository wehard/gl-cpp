#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "camera.h"
#include "text.h"

namespace wgl
{

class Entity;
class Renderer;
class Input;
class Framebuffer;

class Application
{
private:
	GLFWwindow *window;
	std::string title;
	Renderer *renderer;
	double last_time;
	std::vector<Entity *> entities;
	std::vector<Text *> texts;
	bool wireframe_mode;
	Input *input;
	// Framebuffer *frameBuffer;
	int windowWidth;
	int windowHeight;

public:
	Camera *camera;

	Application(std::string title, int windowWidth, int windowHeight);
	Application();
	~Application();
	void init();
	void run();
	void addEntity(Entity *e);
	void addText(Text *text);
	virtual void onAttach() = 0;
	virtual void onUpdate(float deltaTime) = 0;
};

} // namespace wgl

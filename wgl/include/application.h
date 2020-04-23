#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "camera.h"
#include "renderer.h"
#include "text.h"
#include <memory>
namespace wgl
{

class Entity;
class Input;
class Framebuffer;

class Application
{
private:
	GLFWwindow *window;
	std::string title;
	std::vector<Entity *> entities;
	std::vector<Text *> texts;
	double last_time;
	bool wireframe_mode;
	int windowWidth;
	int windowHeight;

	Renderer renderer;
	static Application *instance;

public:

	static Application& Get() { return *instance; }
	Camera camera;

	Application(std::string title, int windowWidth, int windowHeight);
	// Application();
	~Application();
	void init();
	void run();
	void addEntity(Entity *e);
	void addText(Text *text);
	virtual void onAttach() = 0;
	virtual void onUpdate(float deltaTime) = 0;
};

} // namespace wgl

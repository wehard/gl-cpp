#pragma once
#include "core.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "camera.h"
#include "text.h"
#include <memory>
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
	double last_time;
	std::vector<ref<Entity>> entities;
	std::vector<ref<Text>> texts;
	bool wireframe_mode;
	// std::unique_ptr<Input> input;
	scope<Renderer> renderer;
	// Framebuffer *frameBuffer;
	int windowWidth;
	int windowHeight;
	static Application *instance;

public:

	static Application& Get() { return *instance; }
	ref<Camera> camera;

	Application(std::string title, int windowWidth, int windowHeight);
	// Application();
	~Application();
	void init();
	void run();
	void addEntity(ref<Entity> entity);
	void addText(ref<Text> text);
	virtual void onAttach() = 0;
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDetach() = 0;
};

} // namespace wgl

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:56:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 19:08:56 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "camera.h"
#include "renderer.h"
#include "wgl_input.h"
#include "framebuffer.h"
#include "mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


WEngine::WEngine(std::string title) : title(title), wireframe_mode(0)
{
	init();
}

WEngine::WEngine() { }

WEngine::~WEngine() { }

void WEngine::init()
{
	if (!glfwInit())
		std::cout << "GLFW failed to initialize!" << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
		std::cout << "GLEW failed to initialize!" << std::endl;
	camera = new Camera(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT);
	
	renderer = new Renderer(camera);
	WengineInput::setupKeyInputs(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
	// glPolygonMode(GL_FRONT_FACE, GL_LINE);
	glEnable(GL_DEPTH_TEST);

}

void WEngine::run()
{
	Shader *texshader = new Shader("../engine/shaders/texture.vert", "../engine/shaders/texture.frag");
	TexturedQuad *quad = new TexturedQuad();
	Framebuffer *frameBuffer = new Framebuffer();

	onAttach();
	input = new WengineInput(vector<int>({GLFW_KEY_W}));

	last_time = glfwGetTime();
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		if (input->isKeyDown(GLFW_KEY_W))
			wireframe_mode = !wireframe_mode;
		double current_time = glfwGetTime();
		double delta_time = current_time - last_time;

		onUpdate(delta_time);
		
		for (auto e : entities)
			e->update(delta_time);

		// rendering
		frameBuffer->Bind();

		glClearColor(0.2, 0.2, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (wireframe_mode)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		for (auto e : entities)
			renderer->drawEntity(e);

		frameBuffer->Unbind();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, frameBuffer->tex_id);
		texshader->use();
		texshader->setVec2("screen_size", glm::vec2((float)WIN_WIDTH, (float)WIN_HEIGHT));
		renderer->drawTexturedQuad(quad);

		glfwSwapBuffers(window);
		last_time = current_time;
		glfwPollEvents();
	}
}

void WEngine::addEntity(Entity *e)
{
	entities.insert(entities.begin(), e);
	e->id = entities.size();
}

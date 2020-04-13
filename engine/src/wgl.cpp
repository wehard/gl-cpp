/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:56:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:56:13 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "camera.h"
#include "renderer.h"
#include "wgl_input.h"

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
	c = new Camera(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT);
	c->position = glm::vec3(0.0, -30.0, 95.0);
	r = new Renderer(c);
	WengineInput::setupKeyInputs(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
	// glPolygonMode(GL_FRONT_FACE, GL_LINE);
	glEnable(GL_DEPTH_TEST);
}

void WEngine::run()
{
	input = new WengineInput(vector<int>({GLFW_KEY_W}));
	onAttach();

	last_time = glfwGetTime();
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		if (input->isKeyDown(GLFW_KEY_W))
			wireframe_mode = !wireframe_mode;
		double current_time = glfwGetTime();
		double delta_time = current_time - last_time;
		onUpdate(delta_time);
		glClearColor(0.2, 0.2, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (wireframe_mode)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		for (auto e : entities)
		{
			e->update(delta_time);
			r->render(e);
		}

		glm::vec3 cam_target = glm::vec3(entities[1]->position.x / 4.0, -entities[0]->position.y, 95.0);
		if (glm::length(cam_target - c->position) > 0.1)
		{
			float cam_speed = 100.0f;
			glm::vec3 dir = glm::normalize(cam_target - c->position);
			c->position = c->position + dir * (cam_speed * (float)delta_time) * glm::length(cam_target - c->position) / 10.0f;
		}

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

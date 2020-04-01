/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:56:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 14:35:44 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "camera.h"
#include "renderer.h"
#include "wgl_input.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


wgl::wgl(std::string title)
{
	this->title = title;
	init();
}

wgl::wgl() { }

wgl::~wgl() { }

void wgl::init()
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
	c = new camera(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT);
	c->position = glm::vec3(0.0, -30.0, 95.0);
	r = new renderer(c);
	wgl_input::setup_key_inputs(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
	glPolygonMode(GL_FRONT_FACE, GL_LINE);
	glEnable(GL_DEPTH_TEST);
}

void wgl::run()
{
	last_time = glfwGetTime();
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		double current_time = glfwGetTime();
		double delta_time = current_time - last_time;
		glClearColor(0.2, 0.2, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto e : entities)
		{
			e->update(delta_time);
			r->render(e);
		}

		c->position.y = -entities[0]->position.y;
		c->position.x = entities[1]->position.x / 4.0;

		glfwSwapBuffers(window);
		last_time = current_time;
		glfwPollEvents();
	}
}

void wgl::add_entity(entity *e)
{
	entities.insert(entities.begin(), e);
	e->id = entities.size();
}

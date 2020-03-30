/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:56:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 12:05:36 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "renderer.h"

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

	c = camera(45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT);
	c.position = glm::vec3(0.0, 0.0, 72.0);
	r = renderer(&c);
}

void wgl::run()
{
	last_time = glfwGetTime();
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		double current_time = glfwGetTime();
		double delta_time = current_time - last_time;
		glClearColor(0.15, 0.15, 0.15, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto e : entities)
		{
			e->update(delta_time);
			r.render(e);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		last_time = current_time;
	}
}

void wgl::add_entity(entity *e)
{
	entities.insert(entities.begin(), e);
}

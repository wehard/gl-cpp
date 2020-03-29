/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 13:47:19 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "shader.h"
#include "camera.h"
#include "entity.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "renderer.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
       std::cout << "up" << std::endl;
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
       std::cout << "down" << std::endl;
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
       std::cout << "right" << std::endl;
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
       std::cout << "left" << std::endl;
	// && glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS
}

int main(void)
{
	if (!glfwInit())
		std::cout << "GLFW failed to initialize!" << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	GLFWwindow *window;
	window = glfwCreateWindow(1280, 720, "cpp pong", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
		std::cout << "GLEW failed to initialize!" << std::endl;

	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	camera cam = camera();
	shader basic = shader("shaders/basic.vert", "shaders/basic.frag");
	renderer r = renderer(&cam, &basic);

	cam.position = glm::vec3(0.0, 0.0, 72.0);

	entity left = entity();
	left.position = glm::vec3(-64.0, 0.0, 0.0);
	left.scale = glm::vec3(72.0f, 1.0f, 1.0f);
	left.rotation = 90.0;

	entity right = entity();
	right.position = glm::vec3(64.0, 0.0, 0.0);
	right.scale = glm::vec3(72.0f, 1.0f, 1.0f);
	right.rotation = 90.0;

	entity top = entity();
	top.position = glm::vec3(0.0, 36.0, 0.0);
	top.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity bottom = entity();
	bottom.position = glm::vec3(0.0, -36.0, 0.0);
	bottom.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity center = entity();
	center.position = glm::vec3(0.0, 0.0, 0.0);
	center.scale = glm::vec3(60.0f, 1.0f, 1.0f);
	center.rotation = 90.0;

	r.add_entity(&left);
	r.add_entity(&right);
	r.add_entity(&top);
	r.add_entity(&bottom);
	r.add_entity(&center);

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS)
	{
		glClearColor(0.15, 0.15, 0.15, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		r.draw();
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	return (0);
}

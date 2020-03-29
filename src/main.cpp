/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 11:42:44 by wkorande         ###   ########.fr       */
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
	window = glfwCreateWindow(1280, 720, "pong", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
		std::cout << "GLEW failed to initialize!" << std::endl;

	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	camera cam = camera();
	shader basic = shader("shaders/basic.vert", "shaders/basic.frag");
	entity e = entity();
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS)
	{
		glClearColor(0.15, 0.15, 0.15, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basic.use();
		e.position = glm::vec3(5.0, 5.0, 0.0);
		cam.position = glm::vec3(0.0, 0.0, 0.0);
		glm::mat4x4 m = glm::translate(glm::mat4(1.0f), e.position);
		basic.set_mat4("model_matrix", m);
		basic.set_mat4("view_matrix",  cam.get_view_matrix());
		basic.set_mat4("proj_matrix", glm::ortho(0.0, 10.0, 0.0, 10.0));
		e.draw();
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	return (0);
}

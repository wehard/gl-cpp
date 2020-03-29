/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 18:41:07 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
	engine e = engine("engine");
	shader basic = shader("shaders/basic.vert", "shaders/basic.frag");

	entity left = entity(&basic);
	left.position = glm::vec3(-64.0, 0.0, 0.0);
	left.scale = glm::vec3(1.0f, 72.0f, 1.0f);

	entity right = entity(&basic);
	right.position = glm::vec3(64.0, 0.0, 0.0);
	right.scale = glm::vec3(1.0f, 72.0f, 1.0f);

	entity top = entity(&basic);
	top.position = glm::vec3(0.0, 36.0, 0.0);
	top.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity bottom = entity(&basic);
	bottom.position = glm::vec3(0.0, -36.0, 0.0);
	bottom.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity center = entity(&basic);
	center.position = glm::vec3(0.0, 0.0, 0.0);
	center.scale = glm::vec3(60.0f, 1.0f, 1.0f);
	center.rotation = 90.0;

	e.add_entity(&left);
	e.add_entity(&right);
	e.add_entity(&top);
	e.add_entity(&bottom);
	e.add_entity(&center);

	e.run();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl_input.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:30:30 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 16:42:53 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl_input.h"
#include <algorithm>
#include <iostream>

std::vector<wgl_input*> wgl_input::input_instances;

wgl_input::wgl_input(std::vector<int> keys_to_monitor) : is_enabled(true), keys()
{
	input_instances.push_back(this);
	for (int key : keys_to_monitor)
		keys[key] = false;
	std::cout << "constructor" << std::endl;
}

wgl_input::wgl_input() : is_enabled(true), keys() {
	std::cout << "default" << std::endl;
	input_instances.push_back(this);
 }


wgl_input::~wgl_input()
{
	wgl_input::input_instances.erase(std::remove(wgl_input::input_instances.begin(), wgl_input::input_instances.end(), this), wgl_input::input_instances.end());
}

void wgl_input::setup_key_inputs(GLFWwindow *window)
{
	glfwSetKeyCallback(window, glfw_key_callback);
}

void wgl_input::glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_REPEAT)
		return ;
	for (wgl_input* input : input_instances)
	{
		input->set_is_key_down(key, action != GLFW_RELEASE);
	}
}

void wgl_input::set_is_key_down(int key, bool is_down)
{
	if (!is_enabled)
	{
		std::cout << "not enabled! " << key << std::endl;
		return ;
	}
	std::map<int, bool>::iterator it = keys.find(key);
	if (it != keys.end())
	{
		keys[key] = is_down;
	}
}

bool wgl_input::is_key_down(int key)
{
	bool result = false;
	if (is_enabled)
	{
		std::map<int, bool>::iterator it = keys.find(key);
		if (it != keys.end())
		{
			result = keys[key];
		}
	}
	return (result);
}

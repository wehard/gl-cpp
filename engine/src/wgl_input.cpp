/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl_input.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:30:30 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:21:56 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl_input.h"
#include <algorithm>
#include <iostream>

std::vector<WengineInput*> WengineInput::input_instances;

WengineInput::WengineInput(std::vector<int> keys_to_monitor) : is_enabled(true), keys()
{
	input_instances.push_back(this);
	for (int key : keys_to_monitor)
		keys[key] = false;
	// std::cout << "constructor" << std::endl;
}

WengineInput::WengineInput() : is_enabled(true), keys() {
	std::cout << "default" << std::endl;
	input_instances.push_back(this);
 }


WengineInput::~WengineInput()
{
	WengineInput::input_instances.erase(std::remove(WengineInput::input_instances.begin(), WengineInput::input_instances.end(), this), WengineInput::input_instances.end());
}

void WengineInput::setupKeyInputs(GLFWwindow *window)
{
	glfwSetKeyCallback(window, glfwKeyCallback);
}

void WengineInput::glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_REPEAT)
		return ;
	for (WengineInput* input : input_instances)
	{
		input->setIsKeyDown(key, action != GLFW_RELEASE);
	}
}

void WengineInput::setIsKeyDown(int key, bool is_down)
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

bool WengineInput::isKeyDown(int key)
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

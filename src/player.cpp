/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:57:26 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 12:05:01 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <GLFW/glfw3.h>

player::player()
{
	rotation = 0.0;
}

player::~player()
{
}

void player::update(float delta_time)
{
	// if (input->key_down(GLFW_KEY_UP))
	// 	std::cout << "up" << std::endl;
	// if (input->key_down(GLFW_KEY_DOWN))
	// 	std::cout << "down" << std::endl;
	// if (input->key_down(GLFW_KEY_RIGHT))
	// 	std::cout << "right" << std::endl;
	// if (input->key_down(GLFW_KEY_LEFT))
	// 	std::cout << "left" << std::endl;
}

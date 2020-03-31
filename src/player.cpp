/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:57:26 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 09:27:38 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <GLFW/glfw3.h>
#include "wgl_input.h"

player::player(shader *s) : entity(s), speed(100.0)
{
	std::vector<int> ks = {GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT};
	input = new wgl_input(ks);
	rotation = 0.0;
	input->set_is_enabled(true);
}

player::~player()
{
}

void player::update(float delta_time)
{
	if (input->is_key_down(GLFW_KEY_UP))
	{
		if (position.y < 30)
			position.y += speed * delta_time;
	}
	if (input->is_key_down(GLFW_KEY_DOWN))
	{
		if (position.y > -30)
			position.y -= speed * delta_time;
	}
}

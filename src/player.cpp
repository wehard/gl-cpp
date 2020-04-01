/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:57:26 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 12:22:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <GLFW/glfw3.h>
#include "wgl_input.h"

player::player(shader *s, mesh *m) : entity(s, m), speed(70.0)
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
			position.y += speed * delta_time;
	if (input->is_key_down(GLFW_KEY_DOWN))
			position.y -= speed * delta_time;

	float play_area_height = 72.0;
	if (position.y + scale.y / 2 > play_area_height / 2)
		position.y = (play_area_height / 2) - scale.y / 2;
	if (position.y - scale.y / 2 < -play_area_height / 2)
		position.y = (-play_area_height / 2) + scale.y / 2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/02 19:00:24 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opponent.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

opponent::opponent(shader *s, mesh *m, entity *ball) : entity(s, m), ball(ball), speed(50.0)
{
}

opponent::opponent() {}

opponent::~opponent()
{
}

void opponent::update(float delta_time)
{
	if (ball->position.x - ball_prev_pos.x < 0)
	{
		target_y = 0.0;
		if (abs(position.y - target_y) > 1)
		{
			if (target_y > position.y)
				position.y += 1.0 * speed * delta_time;
			else
				position.y -= 1.0 * speed * delta_time;
		}
	}
	else
	{
		float dir = position.y - ball->position.y;
		if (abs(position.y - target_y) > 1)
		{
			target_y = ball->position.y;
		}
		if (dir < 0)
			position.y += 1.0 * speed * delta_time;
		else
			position.y -= 1.0 * speed * delta_time;
	}

	float play_area_height = 72.0;
	if (position.y + scale.y / 2 > play_area_height / 2)
		position.y = (play_area_height / 2) - scale.y / 2;
	if (position.y - scale.y / 2 < -play_area_height / 2)
		position.y = (-play_area_height / 2) + scale.y / 2;
	update_interval += delta_time;
	ball_prev_pos = ball->position;
}

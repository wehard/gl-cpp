/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/03 13:33:55 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opponent.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ball.h"

opponent::opponent(shader *s, mesh *m, ball *b) : entity(s, m), b(b), speed(80.0)
{
}

opponent::opponent() {}

opponent::~opponent()
{
}

void opponent::update(float delta_time)
{
	if (b->get_direction().x < 0)
	{
		target_y = 0.0;
	}
	else
	{
		glm::vec3 p = glm::vec3(position.x, b->position.y, position.z);
		glm::vec3 bp_dir = (p - b->position);
		float t = glm::dot(b->get_direction(), glm::normalize(bp_dir));
		float a = tan(t) * glm::length(bp_dir);
		target_y = b->position.y + a;
		printf("targety: %f\n", target_y);
	}
	if (abs(position.y - target_y) > 1)
	{
		if (target_y > position.y)
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
}

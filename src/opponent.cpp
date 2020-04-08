/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/08 10:37:59 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opponent.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ball.h"

opponent::opponent(shader *s, mesh *m, ball *b) : entity(s, m), b(b), speed(60.0)
{
}

opponent::opponent() {}

opponent::~opponent()
{
}

void opponent::update(float delta_time)
{
	
	glm::vec3 p = glm::vec3(position.x, b->position.y, position.z);
	glm::vec3 bp = p - b->position;
	float adjacent = glm::length(bp);
	float angle = glm::dot(b->get_direction(), glm::normalize(bp));
	float opposite = adjacent * tanf(angle);
	
	if (b->get_direction().y > 0)
		target_y = b->position.y - opposite;
	else
		target_y = b->position.y + opposite;
	// printf("target: %.2f\n", target_y);
	printf("adjacent: %.2f opposite: %.2f angle: %.2f\n", adjacent, opposite, glm::degrees(angle));

	if (b->get_direction().x < 0)
		target_y = 0.0;

	glm::vec3 target = glm::vec3(position.x, target_y, position.z);

	if (glm::length(target - position) > 1)
	{
		glm::vec3 dir = glm::normalize(target - position);
		position = position + dir * (speed * delta_time) * glm::length(target - position) / 10.0f;
		// c->position = c->position + dir * (cam_speed * (float)delta_time) * glm::length(cam_target - c->position) / 10.0f;
	}


	float play_area_height = 72.0;
	if (position.y + scale.y / 2 > play_area_height / 2)
		position.y = (play_area_height / 2) - scale.y / 2;
	if (position.y - scale.y / 2 < -play_area_height / 2)
		position.y = (-play_area_height / 2) + scale.y / 2;
	update_interval += delta_time;
}

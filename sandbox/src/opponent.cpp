/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:32:05 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opponent.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ball.h"

Opponent::Opponent(Shader *s, Mesh *m, Ball *b) : Entity(s, m), b(b), speed(60.0)
{
}

Opponent::Opponent() {}

Opponent::~Opponent()
{
}

void Opponent::update(float delta_time)
{

	glm::vec3 p = glm::vec3(position.x, b->position.y, position.z);
	glm::vec3 bp = p - b->position;
	float adjacent = glm::length(bp);
	float angle = glm::dot(b->get_direction(), glm::normalize(bp));
	float opposite = adjacent * tanf(angle);

	// printf("adjacent: %.2f opposite: %.2f angle: %.2f\n", adjacent, opposite, glm::degrees(angle));
	// printf("ball y: %.2f\n", b->get_direction().y);


	glm::vec3 target = p; // glm::vec3(position.x, target_y, position.z);
	if (b->get_direction().x < 0)
		target.y = -b->position.y/3;

	if (glm::length(target - position) > 1)
	{
		glm::vec3 dir = glm::normalize(target - position);
		position = position + dir * (speed * std::min(abs(glm::length(target - position) / 10.0f), 1.0f)) * delta_time;
		// c->position = c->position + dir * (cam_speed * (float)delta_time) * glm::length(cam_target - c->position) / 10.0f;
	}


	float play_area_height = 72.0;
	if (position.y + scale.y / 2 > play_area_height / 2)
		position.y = (play_area_height / 2) - scale.y / 2;
	if (position.y - scale.y / 2 < -play_area_height / 2)
		position.y = (-play_area_height / 2) + scale.y / 2;
	update_interval += delta_time;
}

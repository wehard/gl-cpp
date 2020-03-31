/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:46 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 15:17:20 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ball.h"

ball::ball(shader *s, mesh *m) : entity(s, m), speed(80)
{
	direction = glm::normalize(glm::vec3(1.0, 0.3, 0.0));
}

ball::~ball() {}

void ball::update(float delta_time)
{
	position = position + direction * speed * delta_time;

	if (position.y > 36) // top wall
		direction = glm::reflect(direction, glm::vec3(0.0, -1.0, 0.0));
	if (position.y < -36) // bottom wall
		direction = glm::reflect(direction, glm::vec3(0.0, 1.0, 0.0));

	if (position.x > 64) // right wall
		direction = glm::reflect(direction, glm::vec3(-1.0, 0.0, 0.0));
	if (position.x < -64) // left wall
		direction = glm::reflect(direction, glm::vec3(1.0, 0.0, 0.0));
}

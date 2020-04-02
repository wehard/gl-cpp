/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:46 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/02 17:51:20 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ball.h"
#include "collider.h"
#include <stdio.h>
#include "player.h"
#include "opponent.h"

#include <bitset> //
#include <iostream>
#include <math.h>

ball::ball(shader *s, mesh *m) : entity(s, m), speed(80)
{
	direction = glm::normalize(glm::vec3(1.0, 0.8, 0.0));
}

ball::~ball() {}

void ball::update(float delta_time)
{
	for (auto &other : entity::entities)
	{
		hit_info h;
		h.normal = glm::vec3(0.0);
		if (other->id != this->id && collider::check_collision(this, other, &h))
		{

			player* p  = dynamic_cast<player*>(h.e);
			opponent *o  = dynamic_cast<opponent*>(h.e);
			if (p || o)
			{
				float i = (position.y - h.e->position.y) / scale.y;
				float d = glm::dot(h.normal, glm::vec3(0.0, 1.0, 0.0));
				if (d >= 1.0 || d <= -1.0)
				{
					printf("h.normal %f %f %f\n", h.normal.x, h.normal.y, h.normal.z);
					if (d > 1.0)
						d = 1.0;
					if (d < -1.0)
						d = -1.0;
					h.normal = glm::vec3(d, 0.0, 0.0);
					i = d;
				}
				float angle = glm::radians(i * 45.0);
				direction.x = h.normal.x * glm::cos(angle) - h.normal.y * glm::sin(angle);
				direction.y = h.normal.x * glm::sin(angle) + h.normal.y * glm::cos(angle);
				direction = glm::normalize(direction);
				// printf("%s d %f i %f angle %f dir: %f %f %f\n", p != NULL ? "player" : "opp", d, i, angle, direction.x, direction.y, direction.z);
				// break;
			}
			else if (!p && !o)
				direction = glm::reflect(direction, h.normal);
			position += (direction * 2.0f);
			// std::cout << std::bitset<8>(h.faces) << " other: " << other->id << std::endl;
			return ;
		}
	}

	position = position + direction * speed * delta_time;
}

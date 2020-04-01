/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:46 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 22:46:50 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ball.h"
#include "collider.h"
#include <stdio.h>
#include "player.h"
#include "opponent.h"

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
		h.normal = glm::vec3(0.0, 1.0, 0.0);
		if (other->id != this->id && collider::check_collision(this, other, &h))
		{
			player* p  = dynamic_cast<player*>(h.e);
			opponent *o  = dynamic_cast<opponent*>(h.e);
			if (p || o)
			{
				printf("hit paddle\n");
				float i = (h.e->position.y - position.y) / scale.y;
				float angle = -glm::radians(i * 75.0);
				direction.x = h.normal.x * glm::cos(angle) - h.normal.y * glm::sin(angle);
				direction.y = h.normal.x * glm::sin(angle) + h.normal.y * glm::cos(angle);
				direction = glm::normalize(direction);
				position -= direction;
				printf("angle %f dir: %f %f %f\n", angle, direction.x, direction.y, direction.z);
				return ;
			}
			else if (!p && !o)
				direction = glm::reflect(direction, h.normal);
			position += h.normal;
			return ;
		}
	}

	position = position + direction * speed * delta_time;
}

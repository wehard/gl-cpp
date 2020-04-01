/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:46 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 17:22:56 by wkorande         ###   ########.fr       */
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
			if (p)
				printf("hit player\n");
			opponent* o  = dynamic_cast<opponent*>(h.e);
			if (o)
				printf("hit opponent\n");
			direction = glm::reflect(direction, h.normal);
			position += h.normal;
			return ;
		}
	}

	position = position + direction * speed * delta_time;
}

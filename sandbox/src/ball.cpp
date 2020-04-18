/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:46 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 15:16:43 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ball.h"
#include "collider.h"
#include <stdio.h>
#include "player.h"
#include "opponent.h"
#include <glm/gtc/random.hpp>
#include <bitset> //
#include <iostream>
#include <math.h>

Ball::Ball(Shader *s, Mesh *m) : Entity(s, m), speed(70), isCaptured(false)
{
	reset_pos_and_dir();
}

Ball::~Ball() {}

void Ball::reset_pos_and_dir()
{
	// position = glm::vec3(0,0,0);
	// direction.x = 0.5 - static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	// direction.y = 0.5 - static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	direction = glm::sphericalRand(1.0);
	direction.y *= 0.5;
	direction.z = 0.0;
	direction = glm::normalize(direction);
	printf("ball dir: %.2f, %.2f, %.2f\n", direction.x, direction.y, direction.z);
}

void Ball::update(float delta_time)
{
	if (isCaptured)
	{
		float offset = 3.0f;
		this->position = capturer->position;
		if (position.x < 0)
			position.x += offset;
		else
			position.x -= offset;
		return;
	}
	for (auto &other : Entity::entities)
	{
		HitInfo h;
		h.normal = glm::vec3(0.0);
		if (other->id != this->id && Collider::checkCollision(this, other, &h))
		{

			Player* p  = dynamic_cast<Player*>(h.e);
			Opponent *o  = dynamic_cast<Opponent*>(h.e);
			if (p || o)
			{
				if (onBallHitCb)
					onBallHitCb(PADDLE);
				float i = (position.y - h.e->position.y) / h.e->scale.y;
				float d = glm::dot(h.normal, glm::vec3(0.0, 1.0, 0.0));
				if (d >= 1.0 || d <= -1.0)
				{
					// printf("h.normal %f %f %f\n", h.normal.x, h.normal.y, h.normal.z);
					if (d > 1.0)
						d = 1.0;
					if (d < -1.0)
						d = -1.0;
					h.normal = glm::vec3(d, 0.0, 0.0);
					i = d;
				}
				float angle = glm::radians(i * 75.0);
				direction.x = h.normal.x * glm::cos(angle) - h.normal.y * glm::sin(angle);
				direction.y = (h.normal.x * glm::sin(angle) + h.normal.y * glm::cos(angle)) * h.normal.x;
				direction = glm::normalize(direction);
				// printf("%s d %f i %f angle %f dir: %f %f %f\n", p != NULL ? "player" : "opp", d, i, angle, direction.x, direction.y, direction.z);
				// break;
			}
			else if (!p && !o)
			{
				if (onBallHitCb)
					onBallHitCb(WALL);
				direction = glm::reflect(direction, h.normal);
			}
			position += (direction * 2.0f);
			// std::cout << std::bitset<8>(h.faces) << " other: " << other->id << std::endl;
			return ;
		}
	}
	position = position + direction * speed * delta_time;
}

glm::vec3 Ball::get_direction()
{
	return (direction);
}

void Ball::capture(Entity *capturer)
{
	this->position = capturer->position;
	isCaptured = true;
	this->capturer = capturer;
}

void Ball::release()
{
	reset_pos_and_dir();
	if (position.x < 0 && direction.x < 0)
		direction.x = -direction.x;
	else if (position.x > 0 && direction.x > 0)
		direction.x = -direction.x;
	// position += (direction * 1.0f);
	isCaptured = false;
	this->capturer = nullptr;
}

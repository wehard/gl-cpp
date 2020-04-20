/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:57:26 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 10:54:37 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <GLFW/glfw3.h>
#include "input.h"
#include "ball.h"

int Player::score = 0;

Player::Player(wgl::Shader *s, wgl::Mesh *m, Ball *ball) : wgl::Entity(s, m), speed(70.0), ball(ball)
{
	std::vector<int> ks = {GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT, GLFW_KEY_SPACE};
	input = new wgl::Input(ks);
	rotation = 0.0;
	input->setIsEnabled(true);
}

Player::~Player()
{
}

void Player::update(float delta_time)
{
	if (input->isKeyDown(GLFW_KEY_SPACE))
	{
		ball->release();
	}
	if (input->isKeyDown(GLFW_KEY_UP))
			position.y += speed * delta_time;
	if (input->isKeyDown(GLFW_KEY_DOWN))
			position.y -= speed * delta_time;

	float play_area_height = 72.0;
	if (position.y + scale.y / 2 > play_area_height / 2)
		position.y = (play_area_height / 2) - scale.y / 2;
	if (position.y - scale.y / 2 < -play_area_height / 2)
		position.y = (-play_area_height / 2) + scale.y / 2;
}


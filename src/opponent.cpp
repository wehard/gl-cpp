/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 15:18:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opponent.h"
#include <GLFW/glfw3.h>

opponent::opponent(shader *s, mesh *m, entity *ball) : entity(s, m), ball(ball), speed(100.0)
{
}

opponent::opponent() {}

opponent::~opponent()
{
}

void opponent::update(float delta_time)
{
	position.y = ball->position.y;
}

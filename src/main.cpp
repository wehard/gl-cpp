/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 09:35:57 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "player.h"
#include "ball.h"
#include "opponent.h"
#include "shader.h"


int main(void)
{
	wgl engine = wgl("wgl");
	shader basic = shader("shaders/basic.vert", "shaders/basic.frag");

	player p = player(&basic);
	p.position = glm::vec3(-60, 0.0, 0.0);
	p.scale = glm::vec3(1.0f, 10.0f, 1.0f);

	ball b = ball(&basic);
	b.position = glm::vec3(-50.0, 0.0, 0.0);

	opponent o = opponent(&basic, &b);
	o.position = glm::vec3(60, 0.0, 0.0);
	o.scale = glm::vec3(1.0f, 10.0f, 1.0f);

	entity left = entity(&basic);
	left.position = glm::vec3(-64.0, 0.0, 0.0);
	left.scale = glm::vec3(1.0f, 72.0f, 1.0f);

	entity right = entity(&basic);
	right.position = glm::vec3(64.0, 0.0, 0.0);
	right.scale = glm::vec3(1.0f, 72.0f, 1.0f);

	entity top = entity(&basic);
	top.position = glm::vec3(0.0, 36.0, 0.0);
	top.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity bottom = entity(&basic);
	bottom.position = glm::vec3(0.0, -36.0, 0.0);
	bottom.scale = glm::vec3(128.0f, 1.0f, 1.0f);

	entity center = entity(&basic);
	center.position = glm::vec3(0.0, 0.0, 0.0);
	center.scale = glm::vec3(60.0f, 1.0f, 1.0f);
	center.rotation = 90.0;

	engine.add_entity(&left);
	engine.add_entity(&right);
	engine.add_entity(&top);
	engine.add_entity(&bottom);
	engine.add_entity(&center);
	engine.add_entity(&o);
	engine.add_entity(&b);
	engine.add_entity(&p);

	engine.run();
	return (0);
}

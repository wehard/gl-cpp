/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:31:43 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "player.h"
#include "ball.h"
#include "opponent.h"
#include "wall.h"
#include "shader.h"
#include "obj_loader.h"
#include "mesh.h"

class Pong : public WEngine
{
	public:
	Pong(string title) : WEngine(title)
	{

	}

	virtual void onAttach() override
	{
	}

	virtual void onUpdate() override
	{
	}
};

int main(void)
{
	Pong pong = Pong("pong");
	Shader basic = Shader("../engine/shaders/phong.vert", "../engine/shaders/phong.frag");
	Mesh *pong_mesh = loadObj("resources/logo.obj");
	Mesh *cube = loadObj("resources/cube.obj");
	Mesh *icosphere = loadObj("resources/icosphere.obj");
	Mesh *paddle = loadObj("resources/cube.obj");

	pong_mesh->setVertexColors(glm::vec4(0.9, 0.1, 0.2, 1.0));
	cube->setVertexColors(glm::vec4(0.2, 0.2, 0.2, 1.0));
	icosphere->setVertexColors(glm::vec4(0.9, 0.9, 0.9, 1.0));
	paddle->setVertexColors(glm::vec4(1.0, 1.0, 1.0, 1.0));

	Entity logo = Entity(&basic, pong_mesh);
	logo.position = glm::vec3(0.0, 0.0, -50.0);
	logo.scale = glm::vec3(10.0f, 10.0f, 10.0f);
	logo.s = &basic;

	Player p = Player(&basic, paddle);
	p.position = glm::vec3(-60, 0.0, 0.0);
	p.scale = glm::vec3(1.0f, 10.0f, 1.0f);

	Ball b = Ball(&basic, icosphere);
	b.scale = glm::vec3(2.0f, 2.0f, 2.0f);

	Opponent o = Opponent(&basic, paddle, &b);
	o.position = glm::vec3(60, 0.0, 0.0);
	o.scale = glm::vec3(1.0f, 10.0f, 1.0f);

	Wall left = Wall(&basic, cube);
	left.position = glm::vec3(-64.0, 0.0, 0.0);
	left.scale = glm::vec3(1.0f, 73.0f, 10.0f);
	left.c->disable();

	Wall right = Wall(&basic, cube);
	right.position = glm::vec3(64.0, 0.0, 0.0);
	right.scale = glm::vec3(1.0f, 73.0f, 10.0f);
	right.c->disable();

	Wall top = Wall(&basic, cube);
	top.position = glm::vec3(0.0, 36.0, 0.0);
	top.scale = glm::vec3(128.0f, 1.0f, 10.0f);

	Wall bottom = Wall(&basic, cube);
	bottom.position = glm::vec3(0.0, -36.0, 0.0);
	bottom.scale = glm::vec3(128.0f, 1.0f, 10.0f);

	Wall center = Wall(&basic, cube);
	center.position = glm::vec3(0.0, 0.0, -2.0);
	center.scale = glm::vec3(1.0f, 72.0f, 1.0f);
	center.c->disable();

	pong.addEntity(&left);
	pong.addEntity(&right);
	pong.addEntity(&top);
	pong.addEntity(&bottom);
	pong.addEntity(&center);
	pong.addEntity(&o);
	pong.addEntity(&logo);
	pong.addEntity(&b);
	pong.addEntity(&p);

	pong.run();
	return (0);
}

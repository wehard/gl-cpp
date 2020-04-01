/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:58:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 14:42:15 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <glm/glm.hpp>
// #include "shader.h"
#include <vector>

class shader;
class mesh;
class collider;

class entity
{
private:
	uint vao_id;
	uint vbo_id;
	uint ebo_id;
	uint cb_id;
	uint nb_id;
	uint uvb_id;
	mesh *m;
	void gen_buffers();
public:
	static std::vector<entity*> entities;
	size_t id;
	collider *c;
	shader *s;
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;
	entity(shader *s, mesh *m);
	entity(mesh *m);
	entity();
	~entity();
	void draw();
	virtual void update(float delta_time);
};

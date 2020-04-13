/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:58:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:25:41 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <glm/glm.hpp>
// #include "shader.h"
#include <vector>
#include "collider.h"

class Shader;
class Mesh;

class Entity
{
private:
	uint vao_id;
	uint vbo_id;
	uint ebo_id;
	uint cb_id;
	uint nb_id;
	uint uvb_id;
	Mesh *m;
	void genBuffers();
public:
	static std::vector<Entity*> entities;
	size_t id;
	Collider *c;
	Shader *s;
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;
	Entity(Shader *s, Mesh *m);
	Entity(Mesh *m);
	Entity();
	~Entity();
	void draw();
	virtual void update(float delta_time);
};

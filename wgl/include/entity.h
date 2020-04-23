/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:58:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 13:42:33 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <vector>
#include "collider.h"
#include "shader.h"
#include "mesh.h"

namespace wgl
{

class Entity
{
protected:
	uint vao_id;
	uint vbo_id;
	uint ebo_id;
	uint cb_id;
	uint nb_id;
	uint uvb_id;
	Mesh mesh;

	void genBuffers();

public:
	static std::vector<Entity *> entities;
	size_t id;
	Collider collider;
	Shader shader;
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;

	Entity();
	Entity(Mesh &mesh);
	Entity(Shader &shader, Mesh &mesh);
	~Entity();
	virtual void draw();
	glm::mat4 getModelMatrix();
	virtual void update(float deltaTime);
};

} // namespace wgl

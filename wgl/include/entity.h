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

#include "core.h"
#include <vector>
#include <glm/glm.hpp>
#include <vector>
#include "collider.h"

namespace wgl
{

class Shader;
class Mesh;

class Entity
{
protected:
	uint vao_id;
	uint vbo_id;
	uint ebo_id;
	uint cb_id;
	uint nb_id;
	uint uvb_id;
	ref<Mesh> mesh;

	void genBuffers();

public:
	size_t id;
	ref<Collider> collider;
	ref<Shader> shader;
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;

	Entity();
	Entity(ref<Mesh> mesh);
	Entity(ref<Shader> shader, ref<Mesh> mesh);
	~Entity();
	virtual void draw();
	glm::mat4 getModelMatrix();
	virtual void update(float deltaTime);
};

} // namespace wgl

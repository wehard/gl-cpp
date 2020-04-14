/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:09:56 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:25:41 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include <stdlib.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "obj_loader.h"
#include "mesh.h"
#include "collider.h"

std::vector<Entity*> Entity::entities;

Entity::Entity(Shader *s, Mesh *m) : s(s), m(m), rotation(0.0)
{
	this->scale = glm::vec3(1.0, 1.0, 1.0);
	this->c = new Collider(m);
	genBuffers();
	Entity::entities.push_back(this);
}

Entity::Entity(Mesh *m)
{
	this->m = m;

}

Entity::Entity() : s(0), rotation(0.0) {}

Entity::~Entity() {}

void Entity::genBuffers()
{
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);

	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &cb_id);
	glGenBuffers(1, &uvb_id);
	glGenBuffers(1, &nb_id);
	glGenBuffers(1, &ebo_id);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m->vertices.size(), &m->vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, cb_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m->colors.size(), &m->colors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, uvb_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m->uvs.size(), &m->uvs[0], GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, nb_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m->normals.size(), &m->normals[0], GL_STATIC_DRAW);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m->indices.size(), &m->indices[0], GL_STATIC_DRAW);
	// should we undbind all buffers here and rebind when drawing?
	// printf("vao: %d vbo: %d uvb: %d, ebo: %d\n", vao_id, vbo_id, uvb_id, ebo_id);
}

void Entity::update(float delta_time) { }

void Entity::draw()
{
	glBindVertexArray(vao_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glDrawElements(GL_TRIANGLES, m->indices.size(), GL_UNSIGNED_INT, 0);
}

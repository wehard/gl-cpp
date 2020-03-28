/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:09:56 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/28 10:13:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include <stdlib.h>
#include <stdio.h>

entity::entity(void)
{
	vertices = {
		-0.5f,	-0.5f,	0.0f,	1.0f, 0.0f, 0.0f,
		-0.5f,	0.5f,	0.0f,	0.0f, 1.0f, 0.0f,
		0.5f,	0.5f,	0.0f,	0.0f, 0.0f, 1.0f,
		0.5f,	-0.5f,	0.0f,	1.0f, 0.0f, 1.0f,
		};

	indices = {0, 1, 2, 2, 3, 0,};

	gen_buffers();

}

entity::~entity()
{

}

void entity::gen_buffers()
{
	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &ebo_id);
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	// should we undbind all buffers here and rebind when drawing?
}

void entity::draw()
{
	glBindVertexArray(vao_id);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:01:04 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 10:38:23 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdio.h>

mesh::mesh(/* args */)
{
}

mesh::~mesh()
{
}

mesh *mesh::quad()
{
	mesh *m = new mesh();
	m->vertices = {
		-0.5f,	-0.5f,	0.0f,
		-0.5f,	0.5f,	0.0f,
		0.5f,	0.5f,	0.0f,
		0.5f,	-0.5f,	0.0f,
		};

	m->colors = {
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
	};

	m->uvs = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
	};

	m->indices = {0, 1, 2, 2, 3, 0,};
	return (m);
}

size_t mesh::num_verts()
{
	return (vertices.size() / 3);
}

void mesh::print(mesh *m)
{
	printf("vertices: %zu\n", m->num_verts());
	for (size_t i = 0; i < m->vertices.size(); i += 3)
	{
		printf("v %.2f, %.2f, %.2f\tn %.2f, %.2f, %.2f\n",
			m->vertices[i], m->vertices[i+1], m->vertices[i+2],
			m->normals[i], m->normals[i+1], m->normals[i+2]
			);
	}

}

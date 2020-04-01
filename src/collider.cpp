/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:34 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 17:34:26 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"
#include "mesh.h"
#include "entity.h"

collider::collider(mesh *m) : m_is_enabled(true)
{
	this->b = mesh::calculate_bounds(m);
}

collider::~collider()
{
}

void collider::enable()
{
	m_is_enabled = true;
}

void collider::disable()
{
	m_is_enabled = false;
}

bool collider::is_enabled()
{
	return (m_is_enabled);
}

bounds transform_bounds(bounds b, glm::vec3 p, glm::vec3 s)
{
	b.x_min = (b.x_min * s.x) + p.x;
	b.y_min = (b.y_min * s.y) + p.y;
	b.z_min = (b.z_min * s.z) + p.z;
	b.x_max = (b.x_max * s.x) + p.x;
	b.y_max = (b.y_max * s.y) + p.y;
	b.z_max = (b.z_max * s.z) + p.z;
	return (b);
}

bool collider::check_collision(entity *e1, entity *e2, hit_info *h)
{
	if (!e1 || !e2 || !e1->c || !e2->c || !e1->c->is_enabled() || !e2->c->is_enabled())
		return (false);
	bounds b1 = transform_bounds(e1->c->b, e1->position, e1->scale);
	bounds b2 = transform_bounds(e2->c->b, e2->position, e2->scale);

	const glm::vec3 face_normals[6] = {
		glm::vec3(1.0, 0.0, 0.0),
		glm::vec3(-1.0, 0.0, 0.0),
		glm::vec3(0.0, 1.0, 0.0),
		glm::vec3(0.0, -1.0, 0.0),
		glm::vec3(0.0, 0.0, 1.0),
		glm::vec3(0.0, 0.0, -1.0)};
	float distance[6] = {
		(b2.x_max - b1.x_min),
		(b1.x_max - b2.x_min),
		(b2.y_max - b1.y_min),
		(b1.y_max - b2.y_min),
		(b2.z_max - b1.z_min),
		(b1.z_max - b2.z_min),
	};
	float min_dist = INFINITY;
	for (int i = 0; i < 6; i++)
	{
		if (distance[i] < 0.0)
			return (false);
		if (i == 0 || distance[i] < min_dist)
		{
			min_dist = distance[i];
			h->normal = face_normals[i];
		}
	}
	h->e = e2;
	return (true);
}

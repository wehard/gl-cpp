/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:34 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 14:37:56 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collider.h"
#include "mesh.h"
#include "entity.h"

collider::collider(mesh *m)
{
	this->b = mesh::calculate_bounds(m);
}

collider::~collider()
{
}

bounds transform_bounds(bounds b, glm::vec3 p)
{
	b.x_min += p.x;
	b.y_min += p.y;
	b.z_min += p.z;
	b.x_max += p.x;
	b.y_max += p.y;
	b.z_max += p.z;
	return (b);
}

bool collider::check_collision(entity *e1, entity *e2)
{
	if (!e1 || !e2 || !e1->c || !e2->c)
		return (false);
	bounds b1 = transform_bounds(e1->c->b, e1->position);
	bounds b2 = transform_bounds(e2->c->b, e2->position);
	return ((b1.x_min <= b2.x_max && b1.x_max >= b2.x_min) &&
			(b1.y_min <= b2.y_max && b1.y_max >= b2.y_min) &&
			(b1.z_min <= b2.z_max && b1.z_max >= b2.z_min));
}

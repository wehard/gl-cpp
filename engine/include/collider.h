/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/02 13:48:49 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "bounds.h"
#include <glm/vec3.hpp>

class mesh;
class entity;

#define FACE_RIGHT (1 << 0)
#define FACE_LEFT (1 << 1)
#define FACE_TOP (1 << 2)
#define FACE_BOTTOM (1 << 3)
#define FACE_FRONT (1 << 4)
#define FACE_BACK (1 << 5)

struct hit_info
{
	entity *e;
	glm::vec3 normal;
	int faces = 0;
};

class collider
{
private:
	bounds b;
	bool m_is_enabled;
public:
	collider(mesh *m);
	~collider();
	void enable();
	void disable();
	bool is_enabled();
	static bool check_collision(entity *e1, entity *e2, hit_info *h, int ignore_mask = 0);
};


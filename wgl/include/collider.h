/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:26:09 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "bounds.h"
#include <glm/vec3.hpp>

namespace wgl
{

class Mesh;
class Entity;

#define FACE_RIGHT (1 << 0)
#define FACE_LEFT (1 << 1)
#define FACE_TOP (1 << 2)
#define FACE_BOTTOM (1 << 3)
#define FACE_FRONT (1 << 4)
#define FACE_BACK (1 << 5)

struct HitInfo
{
	Entity *e;
	glm::vec3 normal;
	int faces = 0;
};

class Collider
{
private:
	Bounds b;
	bool m_is_enabled;

public:
	Collider(Mesh *m);
	~Collider();
	void enable();
	void disable();
	bool isEnabled();
	static bool checkCollision(Entity *e1, Entity *e2, HitInfo *h, int ignore_mask = 0);
};

} // namespace wgl
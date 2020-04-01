/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 17:35:16 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "bounds.h"
#include <glm/vec3.hpp>

class mesh;
class entity;

struct hit_info
{
	entity *e;
	glm::vec3 normal;
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
	static bool check_collision(entity *e1, entity *e2, hit_info *h);
};


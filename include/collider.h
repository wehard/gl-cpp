/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 12:45:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 14:37:03 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "bounds.h"

class mesh;
class entity;

class collider
{
private:
	bounds b;
public:
	collider(mesh *m);
	~collider();
	static bool check_collision(entity *e1, entity *e2);
};


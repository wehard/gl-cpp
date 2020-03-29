/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:51:21 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 12:34:15 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "entity.h"
#include "shader.h"
#include "camera.h"

class renderer
{
private:
	std::vector<entity*> entities;
	shader *s;
	camera *cam;
public:
	renderer(camera *cam, shader *s);
	renderer();
	~renderer();
	void draw();
	void add_entity(entity *e);
	void set_shader(shader *s);
};



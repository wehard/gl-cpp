/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:51:21 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:24:34 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "entity.h"
#include "shader.h"
#include "camera.h"
#include "textured_quad.h"

class Renderer
{
private:
	Camera *cam;
	glm::vec3 light_pos;
public:
	Renderer(Camera *cam);
	Renderer();
	~Renderer();
	void render(Entity *e);
	void drawTexturedQuad(TexturedQuad *quad);
};



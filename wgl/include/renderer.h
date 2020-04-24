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

#include "core.h"
#include <vector>
#include "entity.h"
#include "shader.h"
#include "camera.h"
#include "textured_quad.h"
#include "text.h"
#include <memory>

namespace wgl
{

class Renderer
{
private:
	ref<Camera> camera;
	glm::vec3 lightPos;

public:
	// Renderer();
	Renderer(ref<Camera> camera);
	~Renderer();
	void drawEntity(ref<Entity> entity);
	void drawTexturedQuad(TexturedQuad *quad);
	void drawText(ref<Text> text);
};

} // namespace wgl

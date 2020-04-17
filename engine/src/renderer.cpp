/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:52:19 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:24:33 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include "text.h"

Renderer::Renderer(Camera *cam) : camera(cam), lightPos(glm::vec3(0.0,0.0,50.0))
{
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::drawEntity(Entity *entity)
{
	entity->shader->use();
	entity->shader->setVec3("light_pos", camera->position);
	entity->shader->setVec3("light_color", glm::vec3(1.0, 1.0, 1.0));
	entity->shader->setMat4("view_matrix", camera->getViewMatrix());
	entity->shader->setMat4("proj_matrix", camera->getProjectionMatrix());
	entity->shader->setMat4("model_matrix", entity->getModelMatrix());
	entity->draw();
}

void Renderer::drawTexturedQuad(TexturedQuad *quad)
{
	if (!quad)
		return;
	quad->draw();
}

void Renderer::drawText(Text *text)
{
	text->shader->use();
	text->shader->setMat4("view_matrix", camera->getViewMatrix());
	text->shader->setMat4("proj_matrix", camera->getProjectionMatrix());
	text->draw();
}
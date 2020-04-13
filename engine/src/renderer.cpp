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

Renderer::Renderer(Camera *cam) : cam(cam), light_pos(glm::vec3(0.0,0.0,50.0))
{
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::render(Entity *e)
{
	e->s->use();
	e->s->setVec3("light_pos", cam->position);
	e->s->setVec3("light_color", glm::vec3(1.0, 1.0, 1.0));
	e->s->setMat4("view_matrix", cam->getViewMatrix());
	e->s->setMat4("proj_matrix", cam->getProjectionMatrix());
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), e->scale);
	glm::mat4 translate = glm::translate(glm::mat4(1.0), e->position);
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(e->rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 m = translate * rotate * scale;
	e->s->setMat4("model_matrix", m);
	e->draw();
}

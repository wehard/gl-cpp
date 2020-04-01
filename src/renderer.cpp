/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:52:19 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 12:42:58 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "shader.h"
#include <glm/gtc/matrix_transform.hpp>

renderer::renderer(camera *cam) : cam(cam), light_pos(glm::vec3(0.0,0.0,50.0))
{
}

renderer::renderer()
{
}

renderer::~renderer()
{
}

void renderer::render(entity *e)
{
	e->s->use();
	e->s->set_vec3("light_pos", light_pos);
	e->s->set_vec3("light_color", glm::vec3(1.0, 1.0, 0.8));
	e->s->set_mat4("view_matrix", cam->get_view_matrix());
	e->s->set_mat4("proj_matrix", cam->get_projection_matrix());
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), e->scale);
	glm::mat4 translate = glm::translate(glm::mat4(1.0), e->position);
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(e->rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 m = translate * rotate * scale;
	e->s->set_mat4("model_matrix", m);
	e->draw();
}

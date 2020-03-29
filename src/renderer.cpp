/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:52:19 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 13:25:22 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "shader.h"
#include <glm/gtc/matrix_transform.hpp>

renderer::renderer(camera *cam, shader *s)
{
	this->s = s;
	this->cam = cam;
}

renderer::renderer()
{
}

renderer::~renderer()
{
}

void renderer::draw()
{
	s->use();
	s->set_mat4("view_matrix", cam->get_view_matrix());
	s->set_mat4("proj_matrix", glm::perspective(45.0f, (GLfloat)128 / (GLfloat)72, 0.1f, 150.0f)); // glm::ortho(0.0, 128.0, 0.0, 72.0)
	for (auto e : entities)
	{
		// ModelMatrix = Matrix4.CreateScale(Scale) * Matrix4.CreateRotationX(Rotation.X) * Matrix4.CreateRotationY(Rotation.Y) * Matrix4.CreateRotationZ(Rotation.Z) * Matrix4.CreateTranslation(Position);
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), e->scale);
		glm::mat4 translate = glm::translate(glm::mat4(1.0), e->position);
		glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(e->rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 m = translate * rotate * scale;
		s->set_mat4("model_matrix", m);
		e->draw();
	}
}

void renderer::add_entity(entity *e)
{
	entities.insert(entities.begin(), e);
}

void renderer::set_shader(shader *s)
{
	this->s = s;
}

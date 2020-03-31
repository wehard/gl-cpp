/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 09:46:35 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 09:44:40 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

camera::camera(float fovy, float aspect)
{
	this->position = glm::vec3(0.0, 0.0, 0.0);
	this->projection_matrix = glm::perspective(fovy, aspect, 0.1f, 150.0f);
}
camera::camera() {}
camera::~camera() {}

glm::mat4x4 camera::get_view_matrix()
{
	glm::mat4 view;
	view = glm::lookAt(position,
  		   glm::vec3(0.0f, 0.0f, 0.0f),
  		   glm::vec3(0.0f, 1.0f, 0.0f));
	return (view);
}

glm::mat4x4 camera::get_projection_matrix()
{
	return (projection_matrix);
}

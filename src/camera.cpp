/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 09:46:35 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 09:55:31 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

camera::camera(/* args */)
{
	this->position = glm::vec3(0.0, 0.0, 0.0);
}

camera::~camera() {}

glm::mat4x4 camera::get_view_matrix()
{
	glm::mat4 view;
	view = glm::lookAt(position,
  		   glm::vec3(0.0f, 0.0f, -1.0f),
  		   glm::vec3(0.0f, 1.0f, 0.0f));
	return (view);
}

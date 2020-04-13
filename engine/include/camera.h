/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 09:47:00 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 09:43:13 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class camera
{
private:
	glm::vec3 rotation;
	float	fov;
	glm::mat4x4 projection_matrix;
public:
	glm::vec3 position;
	camera(float fovy, float aspect);
	camera();
	~camera();
	glm::mat4x4 get_view_matrix();
	glm::mat4x4 get_projection_matrix();
};


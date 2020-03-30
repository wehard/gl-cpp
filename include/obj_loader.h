/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:24:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 20:36:10 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

bool load_obj(
	const char *path,
	std::vector<glm::vec3> &out_verts,
	std::vector<glm::vec2> &out_uvs,
	std::vector<glm::vec3> &out_normals,
	std::vector<GLuint> &out_indices
	);
std::vector<float> convert_vec3s(std::vector<glm::vec3> v3s);

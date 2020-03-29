/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:58:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/29 12:58:23 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

class entity
{
private:
	GLuint vao_id;
	GLuint vbo_id;
	GLuint ebo_id;
	GLuint cb_id;
	GLuint uvb_id;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> colors;
	std::vector<GLfloat> uvs;
	void gen_buffers();

public:
	glm::vec3 position;
	glm::vec3 scale;
	float rotation;
	entity(void);
	~entity();
	void draw();
};

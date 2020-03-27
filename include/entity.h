/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:58:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/27 19:31:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <vector>

class entity
{
private:
	GLuint vao_id;
	GLuint vbo_id;
	GLuint ebo_id;
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;
	void gen_buffers();

public:
	entity(void);
	~entity();
	void draw();
};

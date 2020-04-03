/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:53:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/03 12:06:37 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/gl.h>
#include <vector>
#include <glm/vec4.hpp>

struct bounds;

class mesh
{
private:
public:
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> colors;
	std::vector<GLfloat> uvs;
	std::vector<GLfloat> normals;
	size_t	num_verts();
	mesh();
	~mesh();
	void set_vertex_colors(glm::vec4 c);
	static mesh *quad();
	static bounds calculate_bounds(mesh *m);
	static void print(mesh *m);
};


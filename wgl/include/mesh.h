/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:53:38 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:19:00 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/gl.h>
#include <vector>
#include <glm/vec4.hpp>

namespace wgl
{

struct Bounds;

class Mesh
{
private:
public:
	std::vector<GLuint> indices;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> colors;
	std::vector<GLfloat> uvs;
	std::vector<GLfloat> normals;
	size_t getNumVertices();
	Mesh();
	~Mesh();
	void setVertexColors(glm::vec4 c);
	static Mesh *makeQuad();
	static Bounds calculateBounds(Mesh *m);
	static void print(Mesh *m);
};

} // namespace wgl
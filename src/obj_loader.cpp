/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:25:13 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 20:37:25 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_loader.h"
#include <stdio.h>
#include <string.h>
#include <string>

bool load_obj(
	const char *path,
	std::vector<glm::vec3> &out_verts,
	std::vector<glm::vec2> &out_uvs,
	std::vector<glm::vec3> &out_normals,
	std::vector<GLuint> &out_indices
	)
{
	FILE *f = fopen(path, "r");
	if (!f)
	{
		printf("error opening file: %s\n", path);
		return (false);
	}
	char buf[128];
	while (true)
	{
		int res = fscanf(f, "%s", buf);
		if (res == EOF)
			break ;

		if (strcmp(buf, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf(f, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			out_verts.push_back(vertex);
		}
		else if (strcmp(buf, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf(f, "%f %f\n", &uv.x, &uv.y);
			out_uvs.push_back(uv);
		}
		else if (strcmp(buf, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf(f, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			out_normals.push_back(normal);
		}
		else if (strcmp(buf, "f") == 0)
		{
			char s1[10];
			char s2[10];
			char s3[10];
			int vert_index[3];
			fscanf(f, "%s %s %s\n", s1, s2, s3);
			vert_index[0] = atoi(s1);
			vert_index[1] = atoi(s2);
			vert_index[2] = atoi(s3);
			out_indices.push_back(vert_index[0] - 1);
			out_indices.push_back(vert_index[1] - 1);
			out_indices.push_back(vert_index[2] - 1);
		}
	}
	return (true);
}

std::vector<float> convert_vec3s(std::vector<glm::vec3> v3s)
{
	std::vector<float> fs;
	for (auto v : v3s)
	{
		fs.push_back(v.x);
		fs.push_back(v.y);
		fs.push_back(v.z);
	}
	return (fs);
}

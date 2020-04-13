/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:48:23 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/01 11:01:54 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <map>
#include "shader.h"

shader::shader(string vert_path, string frag_path)
{
	this->vert_path = vert_path;
	this->frag_path = frag_path;

	this->v_id = compile_shader(load_shader(this->vert_path), GL_VERTEX_SHADER);
	this->f_id = compile_shader(load_shader(this->frag_path), GL_FRAGMENT_SHADER);
	this->p_id = create_program(this->v_id, this->f_id);
	load_uniforms();
	load_attributes();
}

shader::~shader()
{
}

void shader::use()
{
	glUseProgram(p_id);
}

void shader::set_float(string name, float f)
{
	glUniform1f(uniforms[name], f);
}
void shader::set_vec2(string name, glm::vec2 v)
{
	glUniform2f(uniforms[name], v[0], v[1]);
}

void shader::set_vec3(string name, glm::vec3 v)
{
	glUniform3f(uniforms[name], v[0], v[1], v[2]);
}

void shader::set_mat4(string name, glm::mat4x4 m)
{
	GLuint location = glGetUniformLocation(p_id, name.c_str());
	// std::cout << name << " loc: " << location << std::endl;
	glUniformMatrix4fv(location, 1, GL_FALSE, (GLfloat*)&m[0]);
}

void shader::load_uniforms()
{
	GLint count;

	glGetProgramiv(p_id, GL_ACTIVE_UNIFORMS, &count);
	for (GLint i = 0; i < count; i++)
	{
		GLsizei len;
		GLint size;
		GLenum type;
		GLchar name[30];
		glGetActiveUniform(p_id, i, 30, &len, &size, &type, &name[0]);
		uniforms.insert(std::pair<string, GLuint>(name, (GLuint)i));
	}
	printf("Active uniforms: %d\n", count);


	std::map<std::string, GLuint>::iterator it = uniforms.begin();
	while (it != uniforms.end())
	{
		printf("%5d: %s\n", it->second, it->first.c_str());
		it++;
	}
}

void shader::load_attributes()
{
	GLint count;

	glGetProgramiv(p_id, GL_ACTIVE_ATTRIBUTES, &count);
	for (GLint i = 0; i < count; i++)
	{
		GLsizei len;
		GLint size;
		GLenum type;
		GLchar name[30];
		glGetActiveAttrib(p_id, i, 30, &len, &size, &type, &name[0]);
		attributes.insert(std::pair<string, GLuint>(name, (GLuint)glGetAttribLocation(p_id, name)));
	}
	printf("Active attributes: %d\n", count);


	std::map<std::string, GLuint>::iterator it = attributes.begin();
	while (it != attributes.end())
	{
		printf("%5d: %s\n", it->second, it->first.c_str());
		it++;
	}
}

string shader::load_shader(string path)
{
	std::string source;

	std::ifstream shader_stream(path, std::ios::in);
	if (shader_stream.is_open())
	{
		std::stringstream sstr;
		sstr << shader_stream.rdbuf();
		source = sstr.str();
		shader_stream.close();
	}
	else
		printf("Error opening %s\n", path.c_str());
	return (source);
}

GLuint shader::compile_shader(string src, GLenum shader_type)
{
	GLuint shader_id;

	shader_id = glCreateShader(shader_type);
	const char *source_ptr = src.c_str();
	glShaderSource(shader_id, 1, &source_ptr, NULL);
	glCompileShader(shader_id);
	GLint status = GL_TRUE;
	GLint log_len;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &log_len);
	if (status == GL_FALSE)
	{
		std::vector<char> error_message(log_len + 1);
		glGetShaderInfoLog(shader_id, log_len, NULL, &error_message[0]);
		printf("%s: %s\n", shader_type == GL_FRAGMENT_SHADER ? "frag" : "vert", &error_message[0]);
	}
	return (shader_id);
}

GLuint shader::create_program(GLuint vert_id, GLuint frag_id)
{
	GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vert_id);
	glAttachShader(program_id, frag_id);
	glLinkProgram(program_id);
	glDeleteShader(vert_id);
	glDeleteShader(frag_id);
	return (program_id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:54:41 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/02 13:13:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

class entity;
class camera;
class renderer;
class wgl_input;

class wgl
{
private:
	GLFWwindow	*window;
	std::string	title;
	renderer *r;
	camera *c;
	double last_time;
	std::vector<entity*> entities;
	bool wireframe_mode;
	wgl_input *input;
public:
	wgl(std::string title);
	wgl();
	~wgl();
	void init();
	void run();
	void add_entity(entity *e);
};



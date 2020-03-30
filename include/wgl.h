/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:54:41 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 16:25:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "renderer.h"
#include "camera.h"
#include "entity.h"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

class wgl
{
private:
	GLFWwindow	*window;
	std::string	title;
	std::vector<entity*> entities;
	renderer r;
	camera c;
	double last_time;
	GLFWkeyfun key_callback;
public:
	wgl(std::string title);
	wgl();
	~wgl();
	void init();
	void run();
	void add_entity(entity *e);
};



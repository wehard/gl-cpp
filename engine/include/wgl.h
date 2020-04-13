/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:54:41 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:24:33 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

class Entity;
class Camera;
class Renderer;
class WengineInput;

class WEngine
{
private:
	GLFWwindow *window;
	std::string title;
	Renderer *r;
	Camera *c;
	double last_time;
	std::vector<Entity *> entities;
	bool wireframe_mode;
	WengineInput *input;

public:
	WEngine(std::string title);
	WEngine();
	~WEngine();
	void init();
	void run();
	void addEntity(Entity *e);
	virtual void onAttach() = 0;
	virtual void onUpdate() = 0;
};

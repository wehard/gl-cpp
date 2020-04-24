/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 19:04:20 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"

class TextTest : public wgl::Application
{
private:
	wgl::Input *input;		
public:
	TextTest(std::string title, int windowWidth, int windowHeight) : wgl::Application(title, windowWidth, windowHeight) {}

	virtual void onAttach() override
	{
		input = new wgl::Input({GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT});
		wgl::Shader *textShader = new wgl::Shader("resources/shaders/text.vert", "resources/shaders/text.frag");
		wgl::BitmapFont *font = new wgl::BitmapFont("resources/fonts/classic_console.fnt");
		wgl::Text *text = new wgl::Text(font, "HELLO");
		text->shader = textShader;
		text->position = glm::vec3(-2.5f, 0.0f, 0.0f);
		text->scale = glm::vec3(20.0f, 20.0f, 20.0f);
		text->rotation = 0.0f;
		addText(text);
		camera->position = glm::vec3(0.0f, 0.0f, 5.0f);
	}

	virtual void onUpdate(float deltaTime) override
	{
		if (input->isKeyDown(GLFW_KEY_UP))
			camera->position.z -= 0.1f;
		if (input->isKeyDown(GLFW_KEY_DOWN))
			camera->position.z += 0.1f;
		if (input->isKeyDown(GLFW_KEY_LEFT))
			camera->position.x -= 0.1f;
		if (input->isKeyDown(GLFW_KEY_RIGHT))
			camera->position.x += 0.1f;
	}
};

int main(void)
{
	TextTest test = TextTest("text test", 640, 400);
	test.run();
	return (0);
}

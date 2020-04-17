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
#include "shader.h"
#include "bitmap_font.h"
#include "text.h"
#include "wgl_input.h"

class TextTest : public WEngine
{
private:
	WengineInput *input;		
public:
	TextTest(std::string title) : WEngine(title) {}

	virtual void onAttach() override
	{
		input = new WengineInput({GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT});
		Shader *textShader = new Shader("resources/shaders/text.vert", "resources/shaders/text.frag");
		BitmapFont *font = new BitmapFont("resources/fonts/classic_console.fnt");
		Text *text = new Text(font, "HELLO");
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
	TextTest test = TextTest("text test");
	test.run();
	return (0);
}

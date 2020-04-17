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

class TextTest : public WEngine
{
	private:

public:
	TextTest(std::string title) : WEngine(title) {}

	virtual void onAttach() override
	{
		
		Shader *textShader = new Shader("resources/shaders/texture.vert", "resources/shaders/texture.frag");
		BitmapFont *font = new BitmapFont("resources/fonts/classic_console.fnt");
		Text *text = new Text(font, "hello");
		text->shader = textShader;
		text->position = glm::vec3(0.0f, 0.0f, -0.0f);
		text->scale = glm::vec3(0.0f, 1.0f, 1.0f);
		text->rotation = 0.0f;
		addEntity(text);
	}

	virtual void onUpdate(float deltaTime) override
	{
		
	}
};

int main(void)
{
	TextTest test = TextTest("text test");
	test.run();
	return (0);
}

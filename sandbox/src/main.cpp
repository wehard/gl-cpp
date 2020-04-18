/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 16:35:01 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 15:04:21 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wgl.h"
#include "player.h"
#include "ball.h"
#include "opponent.h"
#include "wall.h"
#include "shader.h"
#include "obj_loader.h"
#include "mesh.h"
#include "texture.h"
#include "textured_quad.h"
#include "bitmap_font.h"
#include "text.h"
#include <string>
#include "wgl_input.h"
#include "ik/irrKlang.h"
#include <functional>

using namespace irrklang;

class Pong : public WEngine
{
private:
	Player *player;
	Opponent *opponent;
	Ball *ball;
	Wall *center;
	Text *player_score_text;
	Text *opp_score_text;
	WengineInput *input;

public:
	ISoundEngine *soundEngine;
	Pong(string title) : WEngine(title) {}
	void resetGame()
	{
		Player::score = 0;
		Opponent::score = 0;
		ball->release();
		ball->reset_pos_and_dir();
		player_score_text->setText(to_string(Player::score));
		opp_score_text->setText(to_string(Opponent::score));
	}

	virtual void onAttach() override
	{
		soundEngine = createIrrKlangDevice();
		input = new WengineInput({GLFW_KEY_R});
		camera->position = glm::vec3(0.0, 0.0, 95.0);
		Shader *basic = new Shader("../resources/shaders/phong.vert", "../resources/shaders/phong.frag");
		Mesh *pong_mesh = loadObj("resources/logo.obj");
		Mesh *cube = loadObj("resources/cube.obj");
		Mesh *icosphere = loadObj("resources/icosphere.obj");
		Mesh *paddle = loadObj("resources/cube.obj");

		pong_mesh->setVertexColors(glm::vec4(0.9, 0.1, 0.2, 1.0));
		cube->setVertexColors(glm::vec4(0.2, 0.2, 0.2, 1.0));
		icosphere->setVertexColors(glm::vec4(0.9, 0.9, 0.9, 1.0));
		paddle->setVertexColors(glm::vec4(1.0, 1.0, 1.0, 1.0));

		Entity *logo = new Entity(basic, pong_mesh);
		logo->position = glm::vec3(0.0, 0.0, -50.0);
		logo->scale = glm::vec3(10.0f, 10.0f, 10.0f);
		logo->shader = basic;

		ball = new Ball(basic, icosphere);
		ball->scale = glm::vec3(2.0f, 2.0f, 2.0f);

		ball->onBallHitCb = [this](ball_hit_type ht){
			if (ht == WALL)
				soundEngine->play2D("sounds/ping_pong_8bit_plop.ogg");
			else if (ht == PADDLE)
				soundEngine->play2D("sounds/ping_pong_8bit_plop.ogg");
		};

		player = new Player(basic, paddle, ball);
		player->position = glm::vec3(-60, 0.0, 0.0);
		player->scale = glm::vec3(1.0f, 10.0f, 1.0f);

		opponent = new Opponent(basic, paddle, ball);
		opponent->position = glm::vec3(60, 0.0, 0.0);
		opponent->scale = glm::vec3(1.0f, 10.0f, 1.0f);

		Wall *left = new Wall(basic, cube);
		left->position = glm::vec3(-64.0, 0.0, 0.0);
		left->scale = glm::vec3(1.0f, 73.0f, 10.0f);
		left->collider->disable();

		Wall *right = new Wall(basic, cube);
		right->position = glm::vec3(64.0, 0.0, 0.0);
		right->scale = glm::vec3(1.0f, 73.0f, 10.0f);
		right->collider->disable();

		Wall *top = new Wall(basic, cube);
		top->position = glm::vec3(0.0, 36.0, 0.0);
		top->scale = glm::vec3(128.0f, 1.0f, 10.0f);

		Wall *bottom = new Wall(basic, cube);
		bottom->position = glm::vec3(0.0, -36.0, 0.0);
		bottom->scale = glm::vec3(128.0f, 1.0f, 10.0f);

		center = new Wall(basic, cube);
		center->position = glm::vec3(0.0f, 0.0f, -10.0f);
		center->scale = glm::vec3(1.0f, 72.0f, 10.0f);
		center->collider->disable();

		BitmapFont *font = new BitmapFont("../resources/fonts/classic_console.fnt");
		player_score_text = new Text(font, to_string(player->score));
		player_score_text->shader = new Shader("../resources/shaders/text.vert", "../resources/shaders/text.frag");
		player_score_text->position = glm::vec3(-62.0f, 28.0f, 5.0f);
		player_score_text->scale = glm::vec3(50.0f, 50.0f, 1.0f);
		player_score_text->rotation = 0.0f;
		addText(player_score_text);

		opp_score_text = new Text(font, to_string(opponent->score));
		opp_score_text->shader = new Shader("../resources/shaders/text.vert", "../resources/shaders/text.frag");
		opp_score_text->position = glm::vec3(50.0f, 28.0f, 5.0f);
		opp_score_text->scale = glm::vec3(46.0f, 50.0f, 1.0f);
		opp_score_text->rotation = 0.0f;
		addText(opp_score_text);

		// addEntity(left);
		// addEntity(right);
		addEntity(top);
		addEntity(bottom);
		// addEntity(center);
		addEntity(opponent);
		addEntity(logo);
		addEntity(ball);
		addEntity(player);
	}

	virtual void onUpdate(float deltaTime) override
	{
		if (input->isKeyDown(GLFW_KEY_R))
			resetGame();
		glm::vec3 cam_target = glm::vec3(ball->position.x / 4.0, -player->position.y, 95.0);
		if (glm::length(cam_target - camera->position) > 0.1)
		{
			float cam_speed = 100.0f;
			glm::vec3 dir = glm::normalize(cam_target - camera->position);
			camera->position = camera->position + dir * (cam_speed * (float)deltaTime) * glm::length(cam_target - camera->position) / 10.0f;
		}
		// float centerZ = glm::sin(glfwGetTime()*10.0f) * 10.0f;
		// center->position.z = centerZ;

		if (ball->position.x < -70 || ball->position.x > 70)
		{
			if (ball->position.x < 0)
			{
				Opponent::score++;
				opp_score_text->setText(to_string(Opponent::score));
				ball->capture(opponent);
			}
			else
			{
				Player::score++;
				player_score_text->setText(to_string(Player::score));
				ball->capture(player);
			}
			ball->speed += 5.0f;
			printf("score: %d-%d\n", Player::score, Opponent::score);
			soundEngine->play2D("sounds/ping_pong_8bit_peeeeeep.ogg");
			// ball->reset_pos_and_dir();
		}
	}
};

int main(void)
{
	Pong pong = Pong("pong");
	pong.run();
	return (0);
}

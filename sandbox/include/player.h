/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/25 16:23:58 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "input.h"

class Ball;

class Player : public wgl::Entity
{
private:
	wgl::Input *input;
	float speed;
	wgl::ref<Ball> ball;
public:
	Player(wgl::ref<wgl::Shader> s, wgl::ref<wgl::Mesh> m, wgl::ref<Ball> ball);
	~Player();
	void update(float delta_time) override;
	static int score;
};



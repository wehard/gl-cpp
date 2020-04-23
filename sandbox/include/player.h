/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 10:53:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "input.h"
#include "ball.h"

class Player : public wgl::Entity
{
private:
	wgl::Input *input;
	float speed;
	Ball ball;
public:
	Player();
	Player(wgl::Shader &s, wgl::Mesh &m, Ball &ball);
	~Player();
	void update(float delta_time) override;
	static int score;
};



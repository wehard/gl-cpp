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

class WengineInput;
class Ball;

class Player : public Entity
{
private:
	WengineInput *input;
	float speed;
	Ball *ball;
public:
	Player(Shader *s, Mesh *m, Ball *ball);
	~Player();
	void update(float delta_time) override;
	static int score;
};



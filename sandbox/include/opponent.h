/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/17 18:55:17 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class Ball;

class Opponent : public Entity
{
private:
	Ball *b;
	float speed;
	float target_y;
	float update_interval = 0.0;
	float delta;
public:
	Opponent(Shader *s, Mesh *m, Ball *b);
	Opponent();
	~Opponent();
	void update(float delta_time) override;
	static int score;
};



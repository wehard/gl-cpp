/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/25 16:24:44 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class Ball;

class Opponent : public wgl::Entity
{
private:
	wgl::ref<Ball> b;
	float speed;
	float target_y;
	float update_interval = 0.0;
	float delta;
public:
	Opponent(wgl::ref<wgl::Shader> s, wgl::ref<wgl::Mesh> m, wgl::ref<Ball> b);
	Opponent();
	~Opponent();
	void update(float delta_time) override;
	static int score;
};



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/18 14:55:15 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include <glm/vec3.hpp>
#include <functional>

enum ball_hit_type {WALL, PADDLE};

class Ball : public Entity
{
private:
	glm::vec3 direction;
	bool isCaptured;
	Entity *capturer;
public:
	float speed;
	Ball(Shader *s, Mesh *m);
	~Ball();
	void update(float delta_time) override;
	glm::vec3 get_direction();
	std::function<void(ball_hit_type)> onBallHitCb;
	void reset_pos_and_dir();
	void capture(Entity *capturer);
	void release();
};

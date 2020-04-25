/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/25 16:31:04 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "wgl.h"
#include "entity.h"
#include <glm/vec3.hpp>
#include <functional>

enum ball_hit_type {WALL, PADDLE};

class Ball : public wgl::Entity
{
private:
	glm::vec3 direction;
	bool isCaptured;
	wgl::ref<Entity> capturer;
public:
	std::vector<wgl::ref<wgl::Entity>> entities;
	float speed;
	Ball(wgl::ref<wgl::Shader> shader, wgl::ref<wgl::Mesh> mesh);
	~Ball();
	void update(float delta_time) override;
	glm::vec3 get_direction();
	std::function<void(ball_hit_type)> onBallHitCb;
	void reset_pos_and_dir();
	void capture(wgl::ref<Entity> capturer);
	void release();
};

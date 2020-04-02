/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/02 18:50:04 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class opponent : public entity
{
private:
	entity *ball;
	float speed;
	float target_y;
	float update_interval = 0.0;
	float delta;
	glm::vec3 ball_prev_pos;
public:
	opponent(shader *s, mesh *m, entity *ball);
	opponent();
	~opponent();
	void update(float delta_time) override;
};



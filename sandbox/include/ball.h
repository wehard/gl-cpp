/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/17 18:55:47 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include <glm/vec3.hpp>

class Ball : public Entity
{
private:
	float speed;
	glm::vec3 direction;
public:
	Ball(Shader *s, Mesh *m);
	~Ball();
	void update(float delta_time) override;
	glm::vec3 get_direction();
	void reset_pos_and_dir();
};

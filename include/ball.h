/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:12:11 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/03 12:21:03 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include <glm/vec3.hpp>

class ball : public entity
{
private:
	float speed;
	glm::vec3 direction;
public:
	ball(shader *s, mesh *m);
	~ball();
	void update(float delta_time) override;
	glm::vec3 get_direction();
};

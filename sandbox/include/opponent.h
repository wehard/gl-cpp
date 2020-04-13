/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/03 12:52:57 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class ball;

class opponent : public entity
{
private:
	ball *b;
	float speed;
	float target_y;
	float update_interval = 0.0;
	float delta;
public:
	opponent(shader *s, mesh *m, ball *b);
	opponent();
	~opponent();
	void update(float delta_time) override;
};



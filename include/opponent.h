/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 18:54:02 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/31 15:18:24 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class opponent : public entity
{
private:
	entity *ball;
	float speed;
public:
	opponent(shader *s, mesh *m, entity *ball);
	opponent();
	~opponent();
	void update(float delta_time) override;
};



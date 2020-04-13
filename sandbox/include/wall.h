/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 13:10:30 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 17:31:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class Wall : public Entity
{
private:
	/* data */
public:
	Wall(Shader *s, Mesh *m);
	~Wall();
};

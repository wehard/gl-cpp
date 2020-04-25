/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 13:10:30 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/25 16:22:44 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

class Wall : public wgl::Entity
{
private:
	/* data */
public:
	Wall(wgl::ref<wgl::Shader> s, wgl::ref<wgl::Mesh> m);
	~Wall();
};

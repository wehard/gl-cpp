/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:19:52 by wkorande          #+#    #+#             */
/*   Updated: 2020/04/13 19:04:47 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Framebuffer
{
private:
	unsigned int fbo_id;
public:
	unsigned int tex_id;
	Framebuffer();
	~Framebuffer();
	void Bind();
	void Unbind();
};

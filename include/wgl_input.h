/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgl_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:05:54 by wkorande          #+#    #+#             */
/*   Updated: 2020/03/30 16:40:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <map>
#include <vector>

class wgl_input
{
private:
	std::map<int, bool> keys;
	bool is_enabled;
public:
	static std::vector<wgl_input*> input_instances;

	wgl_input(std::vector<int> keys);
	wgl_input();
	~wgl_input();
	bool get_is_enabled() { return is_enabled; }
    void set_is_enabled(bool value) { is_enabled = value; }

	static void setup_key_inputs(GLFWwindow *window);
	static void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	void set_is_key_down(int key, bool is_down);
	bool is_key_down(int key);
};


#version 330 core
in vec3 v_pos;
in vec4 v_col;
in vec2 v_uv;

uniform mat4 model_matrix;

out vec4 f_col;

void main()
{
	f_col = v_col + vec4(v_uv, 0.0, 0.0);
	gl_Position = model_matrix * vec4(v_pos, 1.0);
}

#version 330 core
out vec4 col;

in vec2 f_uv;

uniform sampler2D screen_tex;
uniform vec2 screen_tex_size;
in vec4 gl_FragCoord;

void main()
{
	// vec4 lcol = texture(screen_tex, f_uv - vec2(1.0 / screen_tex_size.x, 1.0 / screen_tex_size.y));

	// col = vec4(vec3(1.0 - texture(screen_tex, f_uv)), 1.0); // invert
	col = texture(screen_tex, f_uv);
}

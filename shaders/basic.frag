#version 330
in vec4 f_col;
out vec4 color;

void main()
{
	color = f_col;// * 1.0 - (gl_FragCoord.y / 720);
}

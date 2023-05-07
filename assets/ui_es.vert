#version 300 es

in vec3 position;
in vec3 in_color;

out vec3 out_color;

uniform mat4 projection;

void main ()
{
	gl_Position = projection * vec4 (position, 1.0);

	out_color = in_color;
}

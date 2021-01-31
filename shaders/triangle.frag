#version 330 core
layout(location = 0) out vec4 color;

in vec3 v_Color;
uniform float u_Time;

void main()
{
	color = vec4(v_Color, 1.0f);
}
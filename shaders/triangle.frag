#version 330 core

out vec4 FragColor;
in vec3 v_Color;

uniform float u_Time;

void main()
{
	FragColor = vec4(v_Color, 1.0f);
}
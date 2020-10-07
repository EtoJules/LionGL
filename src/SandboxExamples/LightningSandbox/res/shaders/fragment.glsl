#version 330

out vec4 color;

uniform vec4 u_ObjectColor;
uniform vec4 u_LightColor;

void main() {
    color = vec4(u_LightColor * u_ObjectColor);
}
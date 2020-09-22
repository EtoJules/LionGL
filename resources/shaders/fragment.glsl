#version 330

layout(location = 0) in aPos;
layout(location = 1) in aColor;

out vec3 oColor;

void main() {
    oColor = aColor;
}
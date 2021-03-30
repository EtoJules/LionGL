#version 330

out vec4 color;

in vec2 oTexCoord;

uniform sampler2D u_DiffuseTexture;

void main() {
    color = vec4(texture(u_DiffuseTexture, oTexCoord));
}

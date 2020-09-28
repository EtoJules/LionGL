#version 330

out vec4 color;

in vec2 TexCoord;

uniform sampler2D u_Texture;

void main() {
    color = texture(u_Texture, TexCoord);
}

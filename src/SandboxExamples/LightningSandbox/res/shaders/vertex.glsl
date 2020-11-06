#version 330
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
uniform vec4 u_LightPosition;

out vec3 FragPosition;
out vec3 Normals;
out vec4 LightPosition;

void main() {
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0f);
    FragPosition = vec3(u_View * u_Model * vec4(aPos, 1.0f));
    Normals = mat3(transpose(inverse(u_View * u_Model))) * aNormal;
    LightPosition = u_View * vec4(u_LightPosition.xyz, 1.0f);
}
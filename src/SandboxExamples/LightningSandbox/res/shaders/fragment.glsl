#version 330
out vec4 color;

uniform vec4 u_ObjectColor;
uniform vec4 u_LightColor;
uniform vec4 u_LightPosition;

in vec3 Normals;
in vec3 FragPosition;

void main() {
    //ambiente lightning
    float ambienteStrength = 0.1f;
    vec4 ambient = ambienteStrength * u_LightColor;
    //diffuse lightning
    vec3 norm = normalize(Normals);
    vec3 dirLight = normalize(u_LightPosition.xyz - FragPosition);
    float diff = max(dot(norm, dirLight), 0.0f);
    vec4 diffuse = diff * u_LightColor;

    vec4 result = (ambient + diffuse) * u_ObjectColor;
    color = result;
}
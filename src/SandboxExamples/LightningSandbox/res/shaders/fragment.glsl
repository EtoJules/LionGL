#version 330
out vec4 color;

struct Material{
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
    float shininess;
};
uniform Material u_material;

uniform vec4 u_ObjectColor;
uniform vec4 u_LightColor;

in vec3 FragPosition;
in vec3 Normals;
in vec4 LightPosition;

void main() {
    //ambiente lightning
    float ambienteStrength = 0.2f;
    vec4 ambient = ambienteStrength * u_material.ambient;
    //diffuse lightning
    vec3 norm = normalize(Normals);
    vec3 dirLight = normalize(LightPosition.xyz - FragPosition);
    float diff = max(dot(norm, dirLight), 0.0f);
    vec4 diffuse = u_LightColor * (diff * u_material.diffuse);
    //specular lightning
    float specularStrength = 0.2f;
    vec3 viewDir = normalize(-FragPosition);
    vec3 reflectionDir = reflect(-dirLight, norm);
    float spec = pow(max(dot(viewDir, reflectionDir), 0.0f), u_material.shininess);
    vec4 specular = u_LightColor * (spec * u_material.specular);

    vec4 result = (ambient + diffuse + specular) * u_ObjectColor;
    color = result;
}
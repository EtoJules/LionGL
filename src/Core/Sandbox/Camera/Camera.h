#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

class Camera
{
private:
    glm::vec3 m_position;
    glm::vec3 m_direction;
    float m_yaw;
    float m_pitch;

public:
    explicit Camera(float x = 0.0f, float y = 0.0f, float z = 0.0f);

public:
    void setPosition(glm::vec3 position);
    void setEulerAngle(float yaw, float pitch);
    glm::vec3 getPosition() const;
    glm::vec3 getCameraFront() const;
    glm::vec3 getCameraUp() const;
    glm::mat4 getLookAtMatrix() const;
};
#include "Camera.h"

Camera::Camera(float x, float y, float z)
    : m_position(x, y, z)
{}

void Camera::setPosition(glm::vec3 position)
{
    m_position = position;
}

glm::vec3 Camera::getPosition() const {
    return m_position;
}

glm::mat4 Camera::getLookAtMatrix() const {
    glm::vec3 cameraFront = glm::normalize(m_direction);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 view;

    view = glm::lookAt(m_position, m_position + cameraFront, cameraUp);
    return view;
}

void Camera::setEulerAngle(float yaw, float pitch)
{
    m_direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    m_direction.y = sin(glm::radians(pitch));
    m_direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
}

glm::vec3 Camera::getCameraFront() const
{
    return glm::normalize(m_direction);
}

glm::vec3 Camera::getCameraUp() const
{
    return glm::vec3(0.0f, 1.0f, 0.0f);
}

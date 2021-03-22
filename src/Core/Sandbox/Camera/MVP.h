#pragma once

#include "glm/mat4x4.hpp"

struct MVP{
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    MVP() : model(1.0f), view(1.0f), projection(1.0f){}
};
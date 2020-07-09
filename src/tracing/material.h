#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

namespace Trayracer2 {

class Material {
public:
    Material() : m_diffuseColor(glm::vec3(1.0f))
    {}

    void showPropertiesUI();

    glm::vec3 m_diffuseColor;
};

}

#endif //MATERIAL_H

#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

namespace Trayracer2 {

struct Ray {
    Ray(glm::vec3 o, glm::vec3 d) : origin(o), dir(d) {}

    glm::vec3 origin;
    glm::vec3 dir;
};

}

#endif //RAY_H

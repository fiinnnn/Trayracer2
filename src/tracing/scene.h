#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <glm/glm.hpp>

namespace Trayracer2 {

struct Sphere {
    Sphere(glm::vec3 position, float r) : position(position), r(r)
    {}

    glm::vec3 position;
    float r;
};

class Scene {
public:
    Scene();

    void addSphere(glm::vec3 pos, float r);
    void removeSphere(int i);

    [[nodiscard]] std::vector<Sphere> getSpheres() const
    { return m_spheres; }

private:
    std::vector<Sphere> m_spheres;
};

}

#endif //SCENE_H

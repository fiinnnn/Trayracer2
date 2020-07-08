#ifndef SPHERE_H
#define SPHERE_H

#include <glm/glm.hpp>

#include "scene_object.h"
#include "tracing/ray.h"
#include "tracing/intersection.h"

namespace Trayracer2 {

class Sphere : public SceneObject {
public:
    Sphere(const glm::vec3& pos, float r, const std::string& name = "Sphere")
            : SceneObject(name), m_pos(pos), m_r(r) {}

    [[nodiscard]] Intersection intersect(const Ray& ray) const override;

private:
    glm::vec3 m_pos;
    float m_r;
};

}

#endif //SPHERE_H

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <glm/glm.hpp>

#include "core/core.h"
#include "ray.h"
#include "intersection.h"

namespace Trayracer2 {

class SceneObject;

class Scene {
public:
    Scene();

    void addObject(Ref<SceneObject> obj);

    [[nodiscard]] const std::vector<Ref<SceneObject>>& getObjects() const
    { return m_objects; }

    [[nodiscard]] Intersection intersect(const Ray& ray) const;

private:
    std::vector<Ref<SceneObject>> m_objects;
};

}

#endif //SCENE_H

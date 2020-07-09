#ifndef SCENE_H
#define SCENE_H

#include <unordered_set>
#include <glm/glm.hpp>

#include "core/core.h"
#include "ray.h"
#include "intersection.h"

namespace Trayracer2 {

class SceneObject;

class Scene {
public:
    void addObject(const Ref<SceneObject>& obj);
    void removeObject(const Ref<SceneObject>& obj);

    [[nodiscard]] const std::unordered_set<Ref<SceneObject>>& getObjects() const
    { return m_objects; }

    [[nodiscard]] Intersection intersect(const Ray& ray);

private:
    std::unordered_set<Ref<SceneObject>> m_objects;
};

}

#endif //SCENE_H

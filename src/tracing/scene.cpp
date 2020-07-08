#include "scene.h"

#include "objects/sphere.h"

namespace Trayracer2 {

Scene::Scene()
{
    addObject(createRef<Sphere>(glm::vec3(0, 0, -2.0), 1.0f));
}

void Scene::addObject(Ref<SceneObject> obj)
{
    m_objects.push_back(obj);
}

Intersection Scene::intersect(const Ray& ray) const {
    float mindist = 1000000; //TODO: set far clip plane
    Intersection i{};
    for (auto& object : m_objects) {
        auto cur = object->intersect(ray);
        if (cur.hit && i.dist < mindist) {
            mindist = cur.dist;
            i = cur;
        }
    }
    return i;
}

}

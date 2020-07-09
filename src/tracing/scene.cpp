#include "scene.h"

#include "objects/sphere.h"

namespace Trayracer2 {

void Scene::addObject(const Ref<SceneObject>& obj)
{
    m_objects.insert(obj);
}

void Scene::removeObject(const Ref<SceneObject>& obj)
{
    m_objects.erase(obj);
}

Intersection Scene::intersect(const Ray& ray) {
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

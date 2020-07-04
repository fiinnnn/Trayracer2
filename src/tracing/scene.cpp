#include "scene.h"

namespace Trayracer2 {

Scene::Scene()
{
    addSphere(glm::vec3(0, 0, -2), 2);
}

void Scene::addSphere(glm::vec3 pos, float r)
{
    m_spheres.emplace_back(pos, r);
}

void Scene::removeSphere(int i)
{
    m_spheres.erase(m_spheres.begin() + i);
}

}

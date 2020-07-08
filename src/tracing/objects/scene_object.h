#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <string>

#include "tracing/ray.h"
#include "tracing/intersection.h"

namespace Trayracer2 {

class SceneObject {
public:
    explicit SceneObject(const std::string& name) : m_name(name)
    {}

    virtual ~SceneObject() = default;

    [[nodiscard]] virtual Intersection intersect(const Ray& ray) const = 0;

    [[nodiscard]] std::string getName() const
    { return m_name; }

    void setName(const std::string& name)
    { m_name = name; }

private:
    std::string m_name;
};

}

#endif //SCENE_OBJECT_H

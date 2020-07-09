#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <string>

#include "tracing/ray.h"
#include "tracing/intersection.h"

namespace Trayracer2 {

enum class ObjectType {
    Sphere,
};

class SceneObject {
public:
    SceneObject(const std::string& name, ObjectType type)
        : m_name(name), m_type(type)
    {}

    virtual ~SceneObject() = default;

    [[nodiscard]] virtual Intersection intersect(const Ray& ray) const = 0;

    virtual void showPropertiesUI() = 0;

    [[nodiscard]] std::string getName() const
    { return m_name; }

    void setName(const std::string& name)
    { m_name = name; }

    [[nodiscard]] ObjectType getType() const
    { return m_type; }

    [[nodiscard]] std::string getTypeName() const
    {
        switch (m_type) {
            case ObjectType::Sphere:
                return "Sphere";
        }
    }

private:
    std::string m_name;
    ObjectType m_type;
};

}

#endif //SCENE_OBJECT_H

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>

#include "core/core.h"
#include "rendering/texture2d.h"

namespace Trayracer2 {

struct Color {
    Color(float r, float g, float b) : r(r), g(g), b(b)
    {}

    float r;
    float g;
    float b;
};

struct Ray {
    Ray(glm::vec3 o, glm::vec3 d) : origin(o), dir(d)
    {}

    glm::vec3 origin;
    glm::vec3 dir;
};

struct Sphere {
    Sphere(glm::vec3 position, float r) : position(position), r(r)
    {}

    glm::vec3 position;
    float r;
};

class Raytracer {
public:
    Raytracer();

    void trace();

    void resize(unsigned int width, unsigned int height);

    unsigned int getRenderTargetID()
    { return m_renderTarget->getID(); }

private:
    Ref<Texture2D> m_renderTarget;
    Color* m_buffer;
};

}

#endif //RAYTRACER_H

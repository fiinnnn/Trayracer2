#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>

#include "core/core.h"
#include "rendering/texture2d.h"
#include "tracing/scene.h"
#include "tracing/ray.h"

namespace Trayracer2 {

struct Color {
    Color(float r, float g, float b) : r(r), g(g), b(b)
    {}

    float r;
    float g;
    float b;
};

class Raytracer {
public:
    Raytracer();

    void trace();

    void resize(unsigned int width, unsigned int height);

    [[nodiscard]] unsigned int getWidth() const
    { return m_renderTarget->getWidth(); }

    [[nodiscard]] unsigned int getHeight() const
    { return m_renderTarget->getHeight(); }

    [[nodiscard]] unsigned int getRenderTargetID() const
    { return m_renderTarget->getID(); }

    [[nodiscard]] Ref<Scene> getScene() const
    { return m_scene; }

private:
    Ref<Texture2D> m_renderTarget;
    Color* m_buffer;

    Ref<Scene> m_scene;
};

}

#endif //RAYTRACER_H
